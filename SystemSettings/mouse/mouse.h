#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include <QWidget>

class mouse : public QWidget
{
    Q_OBJECT
public:
    explicit mouse(QWidget *parent = nullptr);

signals:

};

#endif // MOUSE_H
