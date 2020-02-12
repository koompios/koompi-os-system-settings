#ifndef USER_H
#define USER_H

#include <QHBoxLayout>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <QStackedWidget>
#include <QWidget>

class user : public QWidget {
  Q_OBJECT
public:
  explicit user(QWidget *parent = nullptr, QStackedWidget *widget = nullptr);
  QPushButton *SubMenuButton(QPushButton *button, QString name, QString icon);
signals:
private:
  QStackedWidget *getWidget = nullptr;
};

#endif // USER_H
