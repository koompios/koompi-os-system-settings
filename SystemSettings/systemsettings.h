#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class SystemSettings : public QMainWindow {
  Q_OBJECT
public:
  SystemSettings();

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
};

#endif // SYSTEMSETTINGS_H

// UserSetting->setObjectName("UserSettingButton");
// NetworkSettings->setObjectName("NetworkSettingsButton");
// DateTimeSettings->setObjectName("DateTimeSettingsButton");
// ThemeSettings->setObjectName("ThemeSettingsButton");
// DisplaySettings->setObjectName("DisplaySettingsButton");
// SoundSettings->setObjectName("SoundSettingsButton");
// KeyboardSettings->setObjectName("KeyboardSettingsButton");
// MouseSettings->setObjectName("MouseSettingsButton");
// ApplicationSettings->setObjectName("ApplicationSettingsButton");
// SystemHardwareSettings->setObjectName("SystemHardwareSettingsButton");
// SystemUpdateSettings->setObjectName("SystemUpdateSettingsButton");
