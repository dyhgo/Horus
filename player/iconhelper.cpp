#include "iconhelper.h"
#include <QPainter>
#include <QPixmap>

QFont IconHelper::iconfont;

IconHelper::IconHelper() {
    QFontDatabase::removeAllApplicationFonts();
    int fontId = QFontDatabase::addApplicationFont(":/res/font/iconfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconfont = QFont(fontName);
}

void IconHelper::setIcon(QLabel* label, const QString& color, int icon, quint32 size) {
    iconfont.setPixelSize(size);
    label->setFont(iconfont);
    label->setText(QChar(icon));
    if (color != nullptr) label->setStyleSheet(QString("color:") + color);
}

void IconHelper::setIcon(QAbstractButton* button, const QString& color, int icon, quint32 size) {
    iconfont.setPixelSize(size);
    button->setFont(iconfont);
    button->setText(QChar(icon));
    if (color != nullptr) button->setStyleSheet(QString("color:") + color);
}

void IconHelper::setIcon(QAbstractButton* button, const QColor& color, int icon, quint32 size) {
    QPixmap pix = getPixmap(icon, size, color);
    button->setIcon(QIcon(pix));
    button->setIconSize(QSize(size, size));
}

QPixmap IconHelper::getPixmap(int icon, quint32 size, const QColor& color) {
    QPixmap pix(size, size);
    pix.fill(Qt::transparent);
    QPainter painter;
    painter.begin(&pix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    if (color != nullptr) painter.setPen(color);
    iconfont.setPixelSize(size);
    painter.setFont(iconfont);
    painter.drawText(pix.rect(), Qt::AlignCenter, QChar(icon));
    painter.end();
    return pix;
}
