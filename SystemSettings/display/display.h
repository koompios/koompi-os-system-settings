#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>
#include <QWidget>

class display : public QWidget
{
    Q_OBJECT
public:
    explicit display(QWidget *parent = nullptr);

signals:

};

#endif // DISPLAY_H
