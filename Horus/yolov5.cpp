#include "yolov5.h"


void YOLOV5::Initialization(NetConfig conf) {
    this->confThreshold = conf.confThreshold;
    this->nmsThreshold = conf.nmsThreshold;
    this->objThreshold = conf.objThreshold;
    classIds.reserve(20);
    confidences.reserve(20);
    boxes.reserve(20);
    outs.reserve(3);
    indices.reserve(20);
}

bool YOLOV5::loadModel(const char* onnxfile) {

    try {
        this->net = cv::dnn::readNetFromONNX(onnxfile);
        int device_no = cv::cuda::getCudaEnabledDeviceCount();
        if (device_no == 1) {
            this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
            this->net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
        } else {
            QMessageBox::information(nullptr, "warning", QStringLiteral("正在使用CPU推理！\n"), QMessageBox::Yes, QMessageBox::Yes);
        }
        return true;
    } catch (std::exception& e) {
        QMessageBox::critical(nullptr, "Error", QStringLiteral("模型加载出错，请检查重试！\n %1").arg(e.what()), QMessageBox::Yes, QMessageBox::Yes);
        return false;
    }



//    if(1 == cv::cuda::getCudaEnabledDeviceCount()){
//        this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
//        this->net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
//    }
//    this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
//    this->net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
//    this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_INFERENCE_ENGINE);
//    this->net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
}

void YOLOV5::detect(cv::Mat& frame) {
    //Creates 4-dimensional blob from image. (num, channel num, width, height)
    // 预处理
    // scalefactor是像素减去均值后缩放的比例
    // mean 像素减去的平均值，排除光照影响
    //swapRB 默认是bgr是否要变成rgb
    cv::dnn::blobFromImage(frame, blob, 1 / 255.0, cv::Size(this->inpWidth, this->inpHeight), cv::Scalar(0, 0, 0), true, false);
    //Sets the new input value for the network
    this->net.setInput(blob);
    //Runs forward pass to compute outputs of layers listed in @p outBlobNames.
    this->net.forward(outs, this->net.getUnconnectedOutLayersNames());

    /////generate proposals
    classIds.clear();
    confidences.clear();
    boxes.clear();
    // 缩放比例
    float ratioh = static_cast<float>(frame.rows) / this->inpHeight, ratiow = static_cast<float>(frame.cols) / this->inpWidth;
    int n = 0, q = 0, i = 0, j = 0, nout = 8 + 5, c = 0;
    for (n = 0; n < 3; n++) { ///3种分辨率
        int num_grid_x = static_cast<int>(this->inpWidth / this->stride[n]);
        int num_grid_y = static_cast<int>(this->inpHeight / this->stride[n]);
        int area = num_grid_x * num_grid_y;
        this->sigmoid(&outs[static_cast<size_t>(n)], 3 * nout * area);
        for (q = 0; q < 3; q++) {  ///anchor数
            const float anchor_w = this->anchors[n][q * 2];
            const float anchor_h = this->anchors[n][q * 2 + 1];
            float* pdata = (float*)outs[static_cast<size_t>(n)].data + q * nout * area;
            for (i = 0; i < num_grid_y; i++) {
                for (j = 0; j < num_grid_x; j++) {
                    float box_score = pdata[4 * area + i * num_grid_x + j];
                    if (box_score > this->objThreshold) {
                        float max_class_socre = 0, class_socre = 0;
                        int max_class_id = 0;
                        for (c = 0; c < 80; c++) { //// get max socre
                            class_socre = pdata[(c + 5) * area + i * num_grid_x + j];
                            if (class_socre > max_class_socre) {
                                max_class_socre = class_socre;
                                max_class_id = c;
                            }
                        }

                        if (max_class_socre > this->confThreshold) {
                            float cx = (pdata[i * num_grid_x + j] * 2.f - 0.5f + j) * this->stride[n];  ///cx
                            float cy = (pdata[area + i * num_grid_x + j] * 2.f - 0.5f + i) * this->stride[n];   ///cy
                            float w = powf(pdata[2 * area + i * num_grid_x + j] * 2.f, 2.f) * anchor_w;   ///w
                            float h = powf(pdata[3 * area + i * num_grid_x + j] * 2.f, 2.f) * anchor_h;  ///h

                            int left = static_cast<int>((cx - 0.5 * w) * ratiow);
                            int top = static_cast<int>((cy - 0.5 * h) * ratioh); ///坐标还原到原图上

                            classIds.push_back(max_class_id);
                            confidences.push_back(max_class_socre);
                            boxes.push_back(cv::Rect(left, top, static_cast<int>(w * ratiow), static_cast<int>(h * ratioh)));
                        }
                    }
                }
            }
        }
    }

    // Perform non maximum suppression to eliminate redundant overlapping boxes with
    // lower confidences
    indices.clear();
    cv::dnn::NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold, indices);
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        cv::Rect box = boxes[static_cast<size_t>(idx)];
        this->drawPred(classIds[static_cast<size_t>(idx)], confidences[static_cast<size_t>(idx)], box.x, box.y,
                       box.x + box.width, box.y + box.height, frame);
    }
}

void YOLOV5::drawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat& frame) {
    cv::rectangle(frame, cv::Point(left, top), cv::Point(right, bottom), cv::Scalar(0, 0, 255), 3);
    std::string label = cv::format("%.2f", conf);
    label = this->classes[classId] + ":" + label;

    int baseLine;
    cv::Size labelSize = getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = std::max(top, labelSize.height);
    cv::putText(frame, label, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 255, 0), 1);
}

void YOLOV5::sigmoid(cv::Mat* out, int length) {
    float* pdata = (float*)(out->data);
    int i = 0;
    for (i = 0; i < length; i++) {
        pdata[i] = 1.0 / (1 + expf(-pdata[i]));
    }
}




