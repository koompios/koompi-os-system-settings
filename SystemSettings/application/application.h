#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QWidget>

class application : public QObject
{
    Q_OBJECT
public:
    explicit application(QObject *parent = nullptr);

signals:

};

#endif // APPLICATION_H
