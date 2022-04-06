#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QFontDatabase>
#include <QLabel>
#include <QAbstractButton>
#include <QColor>
#include <QObject>

class IconHelper {


  public:
    IconHelper();


  public:


    static QFont iconfont;

  public:

    static void setIcon(QLabel* label, const QString& color, int icon, quint32 size);
    static void setIcon(QAbstractButton* button, const QString& color, int icon, quint32 size);
    static void setIcon(QAbstractButton* button, const QColor& color, int icon, quint32 size);
    static QPixmap getPixmap(int icon, quint32 size, const QColor& color);

};

#endif // ICONHELPER_H
