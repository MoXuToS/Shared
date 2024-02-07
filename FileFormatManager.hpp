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
        if(dbus_error_is_set(&error))
        {
            std::cerr << "Ошибка при создании соединенния DBUS:" << error.message << std::endl;
            dbus_error_free(&error);
        }
    }
    ~Manager()
    {
        dbus_error_free(&error);
    }
    void RegisterFormats(const char *format, const char *Application);
    void OpenFile(const char *filepath);
    private:
    DBusConnection* connection;
    DBusError error;
    const char *objectPath = "/com/example/filemanager";
    const char *interface = "com.example.filemanagerinterface";
    DBusMessage *msg;
};