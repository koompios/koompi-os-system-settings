#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QWidget>

class keyboard : public QWidget
{
    Q_OBJECT
public:
    explicit keyboard(QWidget *parent = nullptr);

signals:

};

#endif // KEYBOARD_H
