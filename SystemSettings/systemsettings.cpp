// Header files
#include "systemsettings.h"
// Dev Tools
#include <QDebug>
// Core Qt
#include <QFile>
#include <QMainWindow>
#include <QString>
#include <QWidget>
// Layouts
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QVBoxLayout>
// UI Components
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
// Style Components
#include <QSizePolicy>

SystemSettings::SystemSettings() {
  QFile file(":/resource/styles/style.qss");
  file.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(file.readAll());
  qDebug() << styleSheet << endl;
  this->setStyleSheet(styleSheet);

  // Declare all variables here
  QString AppName = "System Settings"; // For global name
  QLabel *AppLabel = new QLabel(this);
  QLineEdit *SearchBox = new QLineEdit(this);
  QToolButton *SearchButton = new QToolButton(this);
  QWidget *MainWidget = new QWidget(this);
  QVBoxLayout *MainLayout = new QVBoxLayout(this);
  QHBoxLayout *SearchContainer = new QHBoxLayout(this);
  QVBoxLayout *HeaderContainer = new QVBoxLayout(this);
  QGridLayout *ModuleContainer = new QGridLayout(this);
  QIcon searchIcon = QIcon::fromTheme("search");
  // Initialize variables here

  // 1. App Label
  AppLabel->setText(AppName);
  AppLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  AppLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  AppLabel->setFixedHeight(80);
  AppLabel->setMaximumHeight(80);
  AppLabel->setContentsMargins(0, 0, 0, 0);
  AppLabel->setStyleSheet("font-size: 32px; font-weight: bold;");
  // 2. Search Box
  SearchBox->setPlaceholderText("Search...");
  SearchBox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  SearchBox->setStyleSheet("border: 2px solid #000;");
  SearchBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  SearchBox->setFixedHeight(40);
  SearchBox->setMinimumWidth(350);
  SearchBox->setMaximumWidth(500);
  // 3. Search Button
  SearchButton->setIcon(searchIcon);
  SearchButton->setIconSize(QSize(24, 24));
  SearchButton->setFixedSize(40, 40);
  SearchButton->setStyleSheet("border: 2px solid #000;");
  // 4. Add search components to search layout
  SearchContainer->addStretch(0);
  SearchContainer->addWidget(SearchBox);
  SearchContainer->addWidget(SearchButton);
  SearchContainer->addStretch(0);

  // 5. Header layout
  HeaderContainer->addWidget(AppLabel);
  HeaderContainer->addLayout(SearchContainer);
  HeaderContainer->setStretch(0, 0);

  // 6. Setting list layout
  // 6.1 List of setting buttons
  QIcon userIcon = QIcon::fromTheme("yast-users");
  QToolButton *UserSetting = new QToolButton(this);
  UserSetting->setText("Users");
  UserSetting->setIcon(userIcon);
  UserSetting->setIconSize(QSize(64, 64));
  UserSetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  UserSetting->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  UserSetting->setMaximumSize(QSize(200, 200));
  UserSetting->setMinimumSize(QSize(125, 125));

  QIcon networkIcon = QIcon::fromTheme("yast-network-group");
  QToolButton *NetworkSettings = new QToolButton(this);
  NetworkSettings->setText("Network");
  NetworkSettings->setIcon(networkIcon);
  NetworkSettings->setIconSize(QSize(64, 64));
  NetworkSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  NetworkSettings->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);
  NetworkSettings->setMaximumSize(QSize(200, 200));
  NetworkSettings->setMinimumSize(QSize(125, 125));

  QIcon dateTimeIcon = QIcon::fromTheme("preferences-system-time");
  QToolButton *DateTimeSettings = new QToolButton(this);
  DateTimeSettings->setText("DateTime");
  DateTimeSettings->setIcon(dateTimeIcon);
  DateTimeSettings->setIconSize(QSize(64, 64));
  DateTimeSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  DateTimeSettings->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);
  DateTimeSettings->setMaximumSize(QSize(200, 200));
  DateTimeSettings->setMinimumSize(QSize(125, 125));

  QIcon themeIcon = QIcon::fromTheme("preferences-desktop-theme");
  QToolButton *ThemeSettings = new QToolButton(this);
  ThemeSettings->setObjectName("ThemeButton");
  ThemeSettings->setIcon(themeIcon);
  ThemeSettings->setIconSize(QSize(64, 64));
  ThemeSettings->setText("Themes");
  ThemeSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  ThemeSettings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  ThemeSettings->setMaximumSize(QSize(200, 200));
  ThemeSettings->setMinimumSize(QSize(125, 125));
  ThemeSettings->setContentsMargins(20, 20, 20, 20);

  QIcon displayIcon = QIcon::fromTheme("preferences-desktop-wallpaper");
  QToolButton *DisplaySettings = new QToolButton(this);
  DisplaySettings->setObjectName("ThemeButton");
  DisplaySettings->setIcon(displayIcon);
  DisplaySettings->setIconSize(QSize(64, 64));
  DisplaySettings->setText("Display");
  DisplaySettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  DisplaySettings->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);
  DisplaySettings->setMaximumSize(QSize(200, 200));
  DisplaySettings->setMinimumSize(QSize(125, 125));
  DisplaySettings->setContentsMargins(20, 20, 20, 20);

  QIcon soundIcon = QIcon::fromTheme("preferences-desktop-sound");
  QToolButton *SoundSettings = new QToolButton(this);
  SoundSettings->setObjectName("ThemeButton");
  SoundSettings->setIcon(soundIcon);
  SoundSettings->setIconSize(QSize(64, 64));
  SoundSettings->setText("Sound");
  SoundSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  SoundSettings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  SoundSettings->setMaximumSize(QSize(200, 200));
  SoundSettings->setMinimumSize(QSize(125, 125));
  SoundSettings->setContentsMargins(20, 20, 20, 20);

  QIcon keyboardIcon = QIcon::fromTheme("preferences-desktop-keyboard");
  QToolButton *KeyboardSettings = new QToolButton(this);
  KeyboardSettings->setObjectName("ThemeButton");
  KeyboardSettings->setIcon(keyboardIcon);
  KeyboardSettings->setIconSize(QSize(64, 64));
  KeyboardSettings->setText("Keyboard");
  KeyboardSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  KeyboardSettings->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);
  KeyboardSettings->setMaximumSize(QSize(200, 200));
  KeyboardSettings->setMinimumSize(QSize(125, 125));
  KeyboardSettings->setContentsMargins(20, 20, 20, 20);

  QIcon mouseIcon = QIcon::fromTheme("preferences-desktop-mouse");
  QToolButton *MouseSettings = new QToolButton(this);
  MouseSettings->setObjectName("ThemeButton");
  MouseSettings->setIcon(mouseIcon);
  MouseSettings->setIconSize(QSize(64, 64));
  MouseSettings->setText("Mouse");
  MouseSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  MouseSettings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  MouseSettings->setMaximumSize(QSize(200, 200));
  MouseSettings->setMinimumSize(QSize(125, 125));
  MouseSettings->setContentsMargins(20, 20, 20, 20);

  QIcon appIcon = QIcon::fromTheme("application-octet-stream");
  QToolButton *ApplicationSettings = new QToolButton(this);
  ApplicationSettings->setObjectName("ThemeButton");
  ApplicationSettings->setIcon(appIcon);
  ApplicationSettings->setIconSize(QSize(64, 64));
  ApplicationSettings->setText("Applications");
  ApplicationSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  ApplicationSettings->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);
  ApplicationSettings->setMaximumSize(QSize(200, 200));
  ApplicationSettings->setMinimumSize(QSize(125, 125));
  ApplicationSettings->setContentsMargins(20, 20, 20, 20);

  QIcon systemIcon = QIcon::fromTheme("yast-hwinfo");
  QToolButton *SystemHardwareSettings = new QToolButton(this);
  SystemHardwareSettings->setObjectName("ThemeButton");
  SystemHardwareSettings->setIcon(systemIcon);
  SystemHardwareSettings->setIconSize(QSize(64, 64));
  SystemHardwareSettings->setText("System");
  SystemHardwareSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  SystemHardwareSettings->setSizePolicy(QSizePolicy::Expanding,
                                        QSizePolicy::Expanding);
  SystemHardwareSettings->setMaximumSize(QSize(200, 200));
  SystemHardwareSettings->setMinimumSize(QSize(125, 125));
  SystemHardwareSettings->setContentsMargins(20, 20, 20, 20);

  QIcon updateIcon = QIcon::fromTheme("yast-update");
  QToolButton *SystemUpdateSettings = new QToolButton(this);
  SystemUpdateSettings->setObjectName("ThemeButton");
  SystemUpdateSettings->setIcon(updateIcon);
  SystemUpdateSettings->setIconSize(QSize(64, 64));
  SystemUpdateSettings->setText("Update");
  SystemUpdateSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  SystemUpdateSettings->setSizePolicy(QSizePolicy::Expanding,
                                      QSizePolicy::Expanding);
  SystemUpdateSettings->setMaximumSize(QSize(200, 200));
  SystemUpdateSettings->setMinimumSize(QSize(125, 125));
  SystemUpdateSettings->setContentsMargins(20, 20, 20, 20);

  // 6.2 set button object name
  UserSetting->setObjectName("UserSettingButton");
  NetworkSettings->setObjectName("NetworkSettingsButton");
  DateTimeSettings->setObjectName("DateTimeSettingsButton");
  ThemeSettings->setObjectName("ThemeSettingsButton");
  DisplaySettings->setObjectName("DisplaySettingsButton");
  SoundSettings->setObjectName("SoundSettingsButton");
  KeyboardSettings->setObjectName("KeyboardSettingsButton");
  MouseSettings->setObjectName("MouseSettingsButton");
  ApplicationSettings->setObjectName("ApplicationSettingsButton");
  SystemHardwareSettings->setObjectName("SystemHardwareSettingsButton");
  SystemUpdateSettings->setObjectName("SystemUpdateSettingsButton");

  // 6.3 Add bottons to layout
  ModuleContainer->addWidget(UserSetting, 1, 1);
  ModuleContainer->addWidget(NetworkSettings, 1, 2);
  ModuleContainer->addWidget(DateTimeSettings, 1, 3);
  ModuleContainer->addWidget(ThemeSettings, 2, 1);
  ModuleContainer->addWidget(DisplaySettings, 2, 2);
  ModuleContainer->addWidget(SoundSettings, 2, 3);
  ModuleContainer->addWidget(KeyboardSettings, 3, 1);
  ModuleContainer->addWidget(MouseSettings, 3, 2);
  ModuleContainer->addWidget(ApplicationSettings, 3, 3);
  ModuleContainer->addWidget(SystemHardwareSettings, 4, 1);
  ModuleContainer->addWidget(SystemUpdateSettings, 4, 2);

  MainLayout->addLayout(HeaderContainer);
  MainLayout->addLayout(ModuleContainer);
  MainWidget->setLayout(MainLayout);

  connect(UserSetting, SIGNAL(clicked()), this, SLOT(openUserSetting()));
  connect(NetworkSettings, SIGNAL(clicked()), this,
          SLOT(openNetworkSettings()));
  connect(DateTimeSettings, SIGNAL(clicked()), this,
          SLOT(openDateTimeSettings()));
  connect(ThemeSettings, SIGNAL(clicked()), this, SLOT(openThemeSettings()));
  connect(DisplaySettings, SIGNAL(clicked()), this,
          SLOT(openDisplaySettings()));
  connect(SoundSettings, SIGNAL(clicked()), this, SLOT(openSoundSettings()));
  connect(KeyboardSettings, SIGNAL(clicked()), this,
          SLOT(openKeyboardSettings()));
  connect(MouseSettings, SIGNAL(clicked()), this, SLOT(openMouseSettings()));
  connect(ApplicationSettings, SIGNAL(clicked()), this,
          SLOT(openApplicationSettings()));
  connect(SystemHardwareSettings, SIGNAL(clicked()), this,
          SLOT(openSystemHardwareSettings()));
  connect(SystemUpdateSettings, SIGNAL(clicked()), this,
          SLOT(openSystemUpdateSettings()));

  this->setWindowTitle(AppName);
  this->setCentralWidget(MainWidget);
  this->resize(500, 500);
}

void SystemSettings::openUserSetting() { qDebug() << "UserSetting clicked"; }

void SystemSettings::openNetworkSettings() {
  qDebug() << "NetworkSettings clicked";
}

void SystemSettings::openDateTimeSettings() {
  qDebug() << "DateTimeSettings clicked";
}

void SystemSettings::openThemeSettings() {
  qDebug() << "ThemeSettings clicked";
}

void SystemSettings::openDisplaySettings() {
  qDebug() << "DisplaySettings clicked";
}

void SystemSettings::openSoundSettings() {
  qDebug() << "SoundSettings clicked";
}

void SystemSettings::openKeyboardSettings() {
  qDebug() << "KeyboardSettings clicked";
}

void SystemSettings::openMouseSettings() {
  qDebug() << "MouseSettings clicked";
}

void SystemSettings::openApplicationSettings() {
  qDebug() << "ApplicationSettings clicked";
}

void SystemSettings::openSystemHardwareSettings() {
  qDebug() << "SystemHardwareSettings clicked";
}

void SystemSettings::openSystemUpdateSettings() {
  qDebug() << "SystemUpdateSettings clicked";
}
