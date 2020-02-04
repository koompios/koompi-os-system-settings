cmake_minimum_required(VERSION 3.5)

project(SystemSettings LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_FLAGS -fsanitize=address)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(SystemSettings SHARED
    main.cpp
    systemsettings.cpp
    systemsettings.h
    resource.qrc
    application/application.cpp
    application/application.h
    datetime/datetime.cpp
    datetime/datetime.h
    display/display.cpp
    display/display.h
    hardware/hardware.cpp
    hardware/hardware.h
    keyboard/keyboard.cpp
    keyboard/keyboard.h
    mouse/mouse.cpp
    mouse/mouse.h
    network/network.cpp
    network/network.h
    power/power.cpp
    power/power.h
    sound/sound.cpp
    sound/sound.h
    theme/theme.cpp
    theme/theme.h
    update/update.cpp
    update/update.h
    user/user.cpp
    user/user.h
  )
else()
  add_executable(SystemSettings
    main.cpp
    systemsettings.cpp
    systemsettings.h
    resource.qrc
    application/application.cpp
    application/application.h
    datetime/datetime.cpp
    datetime/datetime.h
    display/display.cpp
    display/display.h
    hardware/hardware.cpp
    hardware/hardware.h
    keyboard/keyboard.cpp
    keyboard/keyboard.h
    mouse/mouse.cpp
    mouse/mouse.h
    network/network.cpp
    network/network.h
    power/power.cpp
    power/power.h
    sound/sound.cpp
    sound/sound.h
    theme/theme.cpp
    theme/theme.h
    update/update.cpp
    update/update.h
    user/user.cpp
    user/user.h
  )
endif()

target_link_libraries(SystemSettings PRIVATE Qt5::Widgets)
