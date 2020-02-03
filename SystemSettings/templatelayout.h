#ifndef TEMPLATELAYOUT_H
#define TEMPLATELAYOUT_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class TemplateLayout : public QWidget
{
    Q_OBJECT
public:
    explicit TemplateLayout(QWidget *parent = nullptr);
    QWidget * AppLayout (
            QWidget * widget,
            QString name
            ) {
        QLabel* appName = new QLabel(this);
        QHBoxLayout * appLayout = new QHBoxLayout(this);
        appName->setText(name);
        appLayout->addWidget(appName);
        widget->setLayout(appLayout);
        return widget;
    }
signals:

};

#endif // TEMPLATELAYOUT_H
