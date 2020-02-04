#ifndef USER_H
#define USER_H

#include <QHBoxLayout>
#include <QLabel>
#include <QObject>
#include <QStackedWidget>
#include <QWidget>
class user : public QWidget {
  Q_OBJECT
public:
  explicit user(QWidget *parent = nullptr, QStackedWidget *widget = nullptr);
signals:
private:
  QStackedWidget *getWidget = nullptr;
};

#endif // USER_H
