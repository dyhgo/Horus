#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>

class AppInit : public QObject {
    Q_OBJECT
  public:
    static AppInit* Instance();
    explicit AppInit(QObject* parent = nullptr);

  protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

  private:
    static QScopedPointer<AppInit> self;
    static void moveWindow(QObject* watched, QEvent* event);
    static void scaleWindow(QObject* watched, QEvent* event);

  signals:

  public slots:
    void start();
};

#endif // APPINIT_H
