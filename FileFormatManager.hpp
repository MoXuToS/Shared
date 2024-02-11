#pragma once
#include<dbus/dbus.h>
#include<vector>
#include<iostream>

class Manager {
    public:
    Manager() 
    {
        dbus_error_init(&error);
        connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
        dbus_bus_register(connection, &error);
        if(dbus_error_is_set(&error))
        {
            std::cerr << "Ошибка при создании соединенния DBUS:" << error.message << std::endl;
            dbus_error_free(&error);
        }
    }

    // Деструктор
    ~Manager()
    {
        dbus_error_free(&error);
    }

    // Регистрация формата
    void RegisterFormat(const std::string format);

    // Регистрация способа запуска файла
    void RegisterOpenType(const std::string format, const std::string Application);

    private:
    DBusMessage *msg;
    DBusConnection *connection;
    DBusError error;
    const char *objectPath = "/com/example/filemanager";
    const char *interface = "com.example.filemanagerinterface";
};