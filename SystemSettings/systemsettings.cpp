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

SystemSettings::SystemSettings()
{
    QFile file(":/resource/styles/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);

    // Declare all variables here
    AppPages = new QStackedWidget;
    QString AppName = "System Settings"; // For global name
    QLabel* AppLabel = new QLabel(this);
    QLineEdit* SearchBox = new QLineEdit(this);
    QToolButton* SearchButton = new QToolButton(this);
    QWidget* MainWidget = new QWidget(this);
    QVBoxLayout* MainLayout = new QVBoxLayout(this);
    QHBoxLayout* SearchContainer = new QHBoxLayout(this);
    QVBoxLayout* HeaderContainer = new QVBoxLayout(this);
    QGridLayout* ModuleContainer = new QGridLayout(this);
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

    QToolButton* UserSetting = new QToolButton(this);
    QToolButton* NetworkSettings = new QToolButton(this);
    QToolButton* DateTimeSettings = new QToolButton(this);
    QToolButton* ThemeSettings = new QToolButton(this);
    QToolButton* DisplaySettings = new QToolButton(this);
    QToolButton* SoundSettings = new QToolButton(this);
    QToolButton* KeyboardSettings = new QToolButton(this);
    QToolButton* MouseSettings = new QToolButton(this);
    QToolButton* ApplicationSettings = new QToolButton(this);
    QToolButton* SystemHardwareSettings = new QToolButton(this);
    QToolButton* SystemUpdateSettings = new QToolButton(this);

    this->MenuButton(UserSetting, "yast-users", "UserSettingButton", "Users");
    this->MenuButton(NetworkSettings, "yast-network-group", "NetworkSettingsButton", "Network");
    this->MenuButton(DateTimeSettings, "preferences-system-time", "DateTimeSettingsButton", "DateTime");
    this->MenuButton(ThemeSettings, "preferences-desktop-theme", "ThemeSettingsButton", "Theme");
    this->MenuButton(DisplaySettings, "preferences-desktop-wallpaper", "DisplaySettingsButton", "Display");
    this->MenuButton(SoundSettings, "preferences-desktop-sound", "SoundSettingsButton", "Sound");
    this->MenuButton(KeyboardSettings, "preferences-desktop-keyboard", "KeyboardSettingsButton", "Keyboard");
    this->MenuButton(MouseSettings, "preferences-desktop-mouse", "MouseSettingsButton", "Mouse");
    this->MenuButton(ApplicationSettings, "application-octet-stream", "ApplicationSettingsButton", "Applications");
    this->MenuButton(SystemHardwareSettings, "yast-hwinfo", "SystemHardwareSettingsButton", "System Hardware");
    this->MenuButton(SystemUpdateSettings, "yast-update", "SystemUpdateSettingsButton", "System Upates");

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

    // Page Labels
    QLabel* UserPageLabel = new QLabel("User Settings");
    QLabel* NetworkPageLabel = new QLabel("Network Settings");
    QLabel* DateTimePageLabel = new QLabel("DateTime Settings");
    QLabel* ThemePageLabel = new QLabel("Theme Settings");
    QLabel* DisplayPageLabel = new QLabel("Display Settings");
    QLabel* SoundPageLabel = new QLabel("Sound Settings");
    QLabel* KeyboardPageLabel = new QLabel("Keyboard Settings");
    QLabel* MousePageLabel = new QLabel("Mouse Settings");
    QLabel* ApplicationPageLabel = new QLabel("Application Settings");
    QLabel* SystemHardwarePageLabel = new QLabel("System Hardware Settings");
    QLabel* SystemUpdatePageLabel = new QLabel("System Update Settings");

    // Page Layout
    QHBoxLayout* UserPageLayout = new QHBoxLayout(this);
    QHBoxLayout* NetworkPageLayout = new QHBoxLayout(this);
    QHBoxLayout* DateTimePageLayout = new QHBoxLayout(this);
    QHBoxLayout* ThemePageLayout = new QHBoxLayout(this);
    QHBoxLayout* DisplayPageLayout = new QHBoxLayout(this);
    QHBoxLayout* SoundPageLayout = new QHBoxLayout(this);
    QHBoxLayout* KeyboardPageLayout = new QHBoxLayout(this);
    QHBoxLayout* MousePageLayout = new QHBoxLayout(this);
    QHBoxLayout* ApplicationPageLayout = new QHBoxLayout(this);
    QHBoxLayout* SystemHardwarePageLayout = new QHBoxLayout(this);
    QHBoxLayout* SystemUpdatePageLayout = new QHBoxLayout(this);
    // BackButton
    QToolButton* UserPageBackHome = new QToolButton(this);
    QToolButton* NetworkPageBackHome = new QToolButton(this);
    QToolButton* DateTimePageBackHome = new QToolButton(this);
    QToolButton* ThemePageBackHome = new QToolButton(this);
    QToolButton* DisplayPageBackHome = new QToolButton(this);
    QToolButton* SoundPageBackHome = new QToolButton(this);
    QToolButton* KeyboardPageBackHome = new QToolButton(this);
    QToolButton* MousePageBackHome = new QToolButton(this);
    QToolButton* ApplicationPageBackHome = new QToolButton(this);
    QToolButton* SystemHardwarePageBackHome = new QToolButton(this);
    QToolButton* SystemUpdatePageBackHome = new QToolButton(this);

    this->HomeButton(UserPageBackHome, "UserPageBackHome", "Back");
    this->HomeButton(NetworkPageBackHome, "NetworkPageBackHome", "Back");
    this->HomeButton(DateTimePageBackHome, "DateTimePageBackHome", "Back");
    this->HomeButton(ThemePageBackHome, "ThemePageBackHome", "Back");
    this->HomeButton(DisplayPageBackHome, "DisplayPageBackHome", "Back");
    this->HomeButton(SoundPageBackHome, "SoundPageBackHome", "Back");
    this->HomeButton(KeyboardPageBackHome, "KeyboardPageBackHome", "Back");
    this->HomeButton(MousePageBackHome, "MousePageBackHome", "Back");
    this->HomeButton(ApplicationPageBackHome, "ApplicationPageBackHome", "Back");
    this->HomeButton(SystemHardwarePageBackHome, "SystemHardwarePageBackHome", "Back");
    this->HomeButton(SystemUpdatePageBackHome, "SystemUpdatePageBackHome", "Back");

    // Add Labels to layouts
    UserPageLayout->addWidget(UserPageBackHome);
    UserPageLayout->addWidget(UserPageLabel);

    NetworkPageLayout->addWidget(NetworkPageBackHome);
    NetworkPageLayout->addWidget(NetworkPageLabel);

    DateTimePageLayout->addWidget(DateTimePageBackHome);
    DateTimePageLayout->addWidget(DateTimePageLabel);

    ThemePageLayout->addWidget(ThemePageBackHome);
    ThemePageLayout->addWidget(ThemePageLabel);

    DisplayPageLayout->addWidget(DisplayPageBackHome);
    DisplayPageLayout->addWidget(DisplayPageLabel);

    SoundPageLayout->addWidget(SoundPageBackHome);
    SoundPageLayout->addWidget(SoundPageLabel);

    KeyboardPageLayout->addWidget(KeyboardPageBackHome);
    KeyboardPageLayout->addWidget(KeyboardPageLabel);

    MousePageLayout->addWidget(MousePageBackHome);
    MousePageLayout->addWidget(MousePageLabel);

    ApplicationPageLayout->addWidget(ApplicationPageBackHome);
    ApplicationPageLayout->addWidget(ApplicationPageLabel);

    SystemHardwarePageLayout->addWidget(SystemHardwarePageBackHome);
    SystemHardwarePageLayout->addWidget(SystemHardwarePageLabel);

    SystemUpdatePageLayout->addWidget(SystemUpdatePageBackHome);
    SystemUpdatePageLayout->addWidget(SystemUpdatePageLabel);

    // Page Widget
    QWidget* PageUserSettings = new QWidget(this);
    QWidget* PageNetworkSettings = new QWidget(this);
    QWidget* PageDateTimeSettings = new QWidget(this);
    QWidget* PageThemeSettings = new QWidget(this);
    QWidget* PageDisplaySettings = new QWidget(this);
    QWidget* PageSoundSettings = new QWidget(this);
    QWidget* PageKeyboardSettings = new QWidget(this);
    QWidget* PageMouseSettings = new QWidget(this);
    QWidget* PageApplicationSettings = new QWidget(this);
    QWidget* PageSystemHardwareSettings = new QWidget(this);
    QWidget* PageSystemUpdateSettings = new QWidget(this);

    PageUserSettings->setLayout(UserPageLayout);
    PageNetworkSettings->setLayout(NetworkPageLayout);
    PageDateTimeSettings->setLayout(DateTimePageLayout);
    PageThemeSettings->setLayout(ThemePageLayout);
    PageDisplaySettings->setLayout(DisplayPageLayout);
    PageSoundSettings->setLayout(SoundPageLayout);
    PageKeyboardSettings->setLayout(KeyboardPageLayout);
    PageMouseSettings->setLayout(MousePageLayout);
    PageApplicationSettings->setLayout(ApplicationPageLayout);
    PageSystemHardwareSettings->setLayout(SystemHardwarePageLayout);
    PageSystemUpdateSettings->setLayout(SystemUpdatePageLayout);

    // Set default page
    AppPages->setCurrentWidget(MainWidget);
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

    // Connect buttons to page
    connect(UserPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(NetworkPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(DateTimePageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(ThemePageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(DisplayPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(SoundPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(KeyboardPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(MousePageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(ApplicationPageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(SystemHardwarePageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));
    connect(SystemUpdatePageBackHome, SIGNAL(clicked()), this, SLOT(openHomePage()));

    connect(UserSetting, SIGNAL(clicked()), this, SLOT(openUserSetting()));
    connect(NetworkSettings, SIGNAL(clicked()), this, SLOT(openNetworkSettings()));
    connect(DateTimeSettings, SIGNAL(clicked()), this, SLOT(openDateTimeSettings()));
    connect(ThemeSettings, SIGNAL(clicked()), this, SLOT(openThemeSettings()));
    connect(DisplaySettings, SIGNAL(clicked()), this, SLOT(openDisplaySettings()));
    connect(SoundSettings, SIGNAL(clicked()), this, SLOT(openSoundSettings()));
    connect(KeyboardSettings, SIGNAL(clicked()), this, SLOT(openKeyboardSettings()));
    connect(MouseSettings, SIGNAL(clicked()), this, SLOT(openMouseSettings()));
    connect(ApplicationSettings, SIGNAL(clicked()), this, SLOT(openApplicationSettings()));
    connect(SystemHardwareSettings, SIGNAL(clicked()), this, SLOT(openSystemHardwareSettings()));
    connect(SystemUpdateSettings, SIGNAL(clicked()), this, SLOT(openSystemUpdateSettings()));

    // App settings
    this->setWindowTitle(AppName);
    this->setCentralWidget(AppPages);
    this->resize(1000, 500);
}

void SystemSettings::openHomePage()
{
    this->AppPages->setCurrentIndex(0);
}

void SystemSettings::openUserSetting()
{
    this->AppPages->setCurrentIndex(1);
}

void SystemSettings::openNetworkSettings()
{
    this->AppPages->setCurrentIndex(2);
}

void SystemSettings::openDateTimeSettings()
{
    this->AppPages->setCurrentIndex(3);
}

void SystemSettings::openThemeSettings()
{
    this->AppPages->setCurrentIndex(4);
}

void SystemSettings::openDisplaySettings()
{
    this->AppPages->setCurrentIndex(5);
}

void SystemSettings::openSoundSettings()
{
    this->AppPages->setCurrentIndex(6);
}

void SystemSettings::openKeyboardSettings()
{
    this->AppPages->setCurrentIndex(7);
}

void SystemSettings::openMouseSettings()
{
    this->AppPages->setCurrentIndex(8);
}

void SystemSettings::openApplicationSettings()
{
    this->AppPages->setCurrentIndex(9);
}

void SystemSettings::openSystemHardwareSettings()
{
    this->AppPages->setCurrentIndex(10);
}

void SystemSettings::openSystemUpdateSettings()
{
    this->AppPages->setCurrentIndex(11);
}
