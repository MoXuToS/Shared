#include<FileFormatManager.hpp>

void Manager::RegisterFormats(const char *format, const char *Application)
{
    DBusMessageIter args;
    msg = dbus_message_new_method_call("com.example.filemanager", objectPath, interface, "RegisterFormat");
    dbus_message_iter_init_append(msg, &args);
    dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &format);
    dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &Application);

    // Отправка сообщений на шину
    dbus_connection_send(connection, msg, NULL);
    dbus_message_unref(msg);
}

void Manager::OpenFile(const char *filepath)
{
    msg = dbus_message_new_method_call("com.example.filemanager", objectPath, interface, "OpenFile");
    if(msg == NULL)
    {
        std::cerr << "Ошибка при создании сообщения." << std::endl;
        return;
    }
    dbus_message_append_args(msg, DBUS_TYPE_STRING, &filepath, DBUS_TYPE_INVALID);

    // Отправка сообщений на шину
    dbus_connection_send(connection, msg, NULL);
    dbus_message_unref(msg);
}