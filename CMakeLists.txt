cmake_minimum_required(VERSION 3.5)
project(DBusExample)

# Поиск пакета D-Bus
find_package(PkgConfig)
pkg_check_modules(DBUS REQUIRED dbus-1)

# Установка путей к заголовочным файлам и библиотекам dbus
include_directories(${DBUS_INCLUDE_DIRS})
link_directories(${DBUS_LIBRARY_DIRS})

# Добавление исходных файлов
set(SOURCES
    main.cpp
    FileFormatManager.cpp
)

# Добавление заголовочных файлов
set(HEADERS
    FileFormatManager.hpp
)

# Добавление исполняемого файла
add_executable(DBusExample ${SOURCES})

# Линковка библиотеки dbus
target_link_libraries(DBusExample ${DBUS_LIBRARIES})
