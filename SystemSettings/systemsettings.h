#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H
// Header files
#include <QIcon>
#include <QMainWindow>
#include <QObject>
#include <QSizePolicy>
#include <QStackedWidget>
#include <QToolButton>
#include <QWidget>

#include "user/user.h"
#include <memory>

class SystemSettings : public QMainWindow {
  Q_OBJECT
public:
  SystemSettings();

  QToolButton *MenuButton(QToolButton *button, const QString &iconName,
                          const QString &buttonID, const QString &buttonName) {
    QIcon buttonicon = QIcon::fromTheme(iconName);
    button->setObjectName(buttonID);
    button->setIcon(buttonicon);
    button->setIconSize(QSize(64, 64));
    button->setText(buttonName);
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button->setMaximumSize(QSize(200, 200));
    button->setMinimumSize(QSize(125, 125));
    button->setContentsMargins(20, 20, 20, 20);
    button->setAutoRaise(true);
    return button;
  }

  QToolButton *HomeButton(QToolButton *homeButton, const QString &buttonID,
                          const QString &buttonName) {
    QIcon homeIcon = QIcon::fromTheme("go-home");
    homeButton->setObjectName(buttonID);
    homeButton->setText(buttonName);
    homeButton->setIcon(homeIcon);
    homeButton->setIconSize(QSize(24, 24));
    homeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    homeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    homeButton->setGeometry(0, 0, 100, 40);
    homeButton->setStyleSheet("color: #000 !important;");
    homeButton->setAutoRaise(true);
    return homeButton;
  }

public slots:
  void openHomePage();

private slots:
  void openUserSetting();
  void openNetworkSettings();
  void openDateTimeSettings();
  void openThemeSettings();
  void openDisplaySettings();
  void openSoundSettings();
  void openKeyboardSettings();
  void openMouseSettings();
  void openApplicationSettings();
  void openSystemHardwareSettings();
  void openSystemUpdateSettings();

private:
  QStackedWidget *AppPages = nullptr;
  user *UserPage = nullptr;
};

#endif // SYSTEMSETTINGS_H
