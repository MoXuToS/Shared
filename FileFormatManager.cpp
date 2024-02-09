#include "FileFormatManager.hpp"

void Manager::RegisterFormats(const std::string format,const std::string Application) 
{
    DBusMessage *msg;
    DBusMessageIter args;
    msg = dbus_message_new_method_call("com.example.filemanager", objectPath, interface, "RegisterFormat");

    dbus_message_iter_init_append(msg, &args);
    dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &format);
    dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &Application);
    if(!dbus_connection_send(connection, msg, NULL))
        std::cerr << "Failed to send message" << std::endl;


    dbus_connection_flush(connection);

    dbus_message_unref(msg);
}

void Manager::OpenFile(const std::string filepath) 
{
    DBusMessage *msg;
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

bool Manager::FormatIsRegistred(const std::string filepath)
{
    DBusMessage *reply;
    DBusMessageIter args;
    DBusMessage *msg = dbus_message_new_method_call("com.example.filemanager", objectPath, interface, "CheckRegistred");
    dbus_message_iter_init_append(msg, &args);
    dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &filepath);
    reply = dbus_connection_send_with_reply_and_block(connection, msg, -1, &error);
    if(!reply)
    {
        std::cerr << "Failed to call method: " << error.message << std::endl;
        dbus_error_free(&error);
        return false;
    }

    dbus_message_unref(reply);
    dbus_message_unref(msg);

    return true;
}