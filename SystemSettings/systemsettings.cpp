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
#include <QStackedWidget>
#include <QVBoxLayout>
// UI Components
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
// Style Components
#include <QSizePolicy>

SystemSettings::SystemSettings() {
  QFile file(":/resource/styles/style.css");
  file.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(file.readAll());
  this->setStyleSheet(styleSheet);

  // Declare all variables here
  AppPages = new QStackedWidget;
  QString AppName = "System Settings"; // For global name
  QLabel *AppLabel = new QLabel(this);
  QLineEdit *SearchBox = new QLineEdit(this);
  QToolButton *SearchButton = new QToolButton(this);
  QWidget *MainWidget = new QWidget(this);
  //  QVBoxLayout* MainLayout = new QVBoxLayout(this);
  //  QHBoxLayout* SearchContainer = new QHBoxLayout(this);
  //  QVBoxLayout* HeaderContainer = new QVBoxLayout(this);
  //  QGridLayout* ModuleContainer = new QGridLayout(this);

  QVBoxLayout *MainLayout = new QVBoxLayout;
  QHBoxLayout *SearchContainer = new QHBoxLayout;
  QVBoxLayout *HeaderContainer = new QVBoxLayout;
  QGridLayout *ModuleContainer = new QGridLayout;

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

  QToolButton *UserSetting = new QToolButton(this);
  QToolButton *NetworkSettings = new QToolButton(this);
  QToolButton *DateTimeSettings = new QToolButton(this);
  QToolButton *ThemeSettings = new QToolButton(this);
  QToolButton *DisplaySettings = new QToolButton(this);
  QToolButton *SoundSettings = new QToolButton(this);
  QToolButton *KeyboardSettings = new QToolButton(this);
  QToolButton *MouseSettings = new QToolButton(this);
  QToolButton *ApplicationSettings = new QToolButton(this);
  QToolButton *SystemHardwareSettings = new QToolButton(this);
  QToolButton *SystemUpdateSettings = new QToolButton(this);

  this->MenuButton(UserSetting, "yast-users", "UserSettingButton", "Users");
  this->MenuButton(NetworkSettings, "yast-network-group",
                   "NetworkSettingsButton", "Network");
  this->MenuButton(DateTimeSettings, "preferences-system-time",
                   "DateTimeSettingsButton", "DateTime");
  this->MenuButton(ThemeSettings, "preferences-desktop-theme",
                   "ThemeSettingsButton", "Theme");
  this->MenuButton(DisplaySettings, "preferences-desktop-wallpaper",
                   "DisplaySettingsButton", "Display");
  this->MenuButton(SoundSettings, "preferences-desktop-sound",
                   "SoundSettingsButton", "Sound");
  this->MenuButton(KeyboardSettings, "preferences-desktop-keyboard",
                   "KeyboardSettingsButton", "Keyboard");
  this->MenuButton(MouseSettings, "preferences-desktop-mouse",
                   "MouseSettingsButton", "Mouse");
  this->MenuButton(ApplicationSettings, "application-octet-stream",
                   "ApplicationSettingsButton", "Applications");
  this->MenuButton(SystemHardwareSettings, "yast-hwinfo",
                   "SystemHardwareSettingsButton", "System Hardware");
  this->MenuButton(SystemUpdateSettings, "yast-update",
                   "SystemUpdateSettingsButton", "System Upates");

  // 6.2 Add bottons to layout
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

  // Page Widget
  QWidget *PageUserSettings = new QWidget(this);
  QWidget *PageNetworkSettings = new QWidget(this);
  QWidget *PageDateTimeSettings = new QWidget(this);
  QWidget *PageThemeSettings = new QWidget(this);
  QWidget *PageDisplaySettings = new QWidget(this);
  QWidget *PageSoundSettings = new QWidget(this);
  QWidget *PageKeyboardSettings = new QWidget(this);
  QWidget *PageMouseSettings = new QWidget(this);
  QWidget *PageApplicationSettings = new QWidget(this);
  QWidget *PageSystemHardwareSettings = new QWidget(this);
  QWidget *PageSystemUpdateSettings = new QWidget(this);

  PageUserSettings = new user(this, AppPages);

  // Add widgets to page
  AppPages->addWidget(MainWidget);
  AppPages->addWidget(PageUserSettings);
  AppPages->addWidget(PageNetworkSettings);
  AppPages->addWidget(PageDateTimeSettings);
  AppPages->addWidget(PageThemeSettings);
  AppPages->addWidget(PageDisplaySettings);
  AppPages->addWidget(PageSoundSettings);
  AppPages->addWidget(PageKeyboardSettings);
  AppPages->addWidget(PageMouseSettings);
  AppPages->addWidget(PageApplicationSettings);
  AppPages->addWidget(PageSystemHardwareSettings);
  AppPages->addWidget(PageSystemUpdateSettings);

  // Set default page
  AppPages->setCurrentWidget(MainWidget);

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

  // App settings
  this->setWindowTitle(AppName);
  this->setCentralWidget(AppPages);
  this->resize(1000, 500);
}

void SystemSettings::openHomePage() { this->AppPages->setCurrentIndex(0); }

void SystemSettings::openUserSetting() { this->AppPages->setCurrentIndex(1); }

void SystemSettings::openNetworkSettings() {
  this->AppPages->setCurrentIndex(2);
}

void SystemSettings::openDateTimeSettings() {
  this->AppPages->setCurrentIndex(3);
}

void SystemSettings::openThemeSettings() { this->AppPages->setCurrentIndex(4); }

void SystemSettings::openDisplaySettings() {
  this->AppPages->setCurrentIndex(5);
}

void SystemSettings::openSoundSettings() { this->AppPages->setCurrentIndex(6); }

void SystemSettings::openKeyboardSettings() {
  this->AppPages->setCurrentIndex(7);
}

void SystemSettings::openMouseSettings() { this->AppPages->setCurrentIndex(8); }

void SystemSettings::openApplicationSettings() {
  this->AppPages->setCurrentIndex(9);
}

void SystemSettings::openSystemHardwareSettings() {
  this->AppPages->setCurrentIndex(10);
}

void SystemSettings::openSystemUpdateSettings() {
  this->AppPages->setCurrentIndex(11);
}
