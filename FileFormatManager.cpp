#include "FileFormatManager.hpp"

void Manager::RegisterFormat(const std::string format) 
{
    DBusMessageIter args;
    msg = dbus_message_new_signal(objectPath, interface, "RegisterFormat");

    dbus_message_append_args(msg, DBUS_TYPE_STRING, &format, DBUS_TYPE_INVALID);
    if(!dbus_connection_send(connection, msg, NULL))
        std::cerr << "Failed to send message" << std::endl;

    dbus_message_unref(msg);
}

void Manager::RegisterOpenType(const std::string format, const std::string Application)
{
    DBusMessageIter iter;
    msg = dbus_message_new_signal(objectPath, interface, "RegisterOpenType");
    dbus_message_iter_init_append(msg, &iter);
    dbus_message_iter_open_container(&iter, DBUS_TYPE_ARRAY, DBUS_TYPE_ARRAY_AS_STRING, &iter);
    dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, format.c_str());
    dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, Application.c_str());
    dbus_message_iter_close_container(&iter, &iter);

    if(!dbus_connection_send(connection, msg, NULL))
        std::cerr << "Ошибка при отправки сообщения на щину dbus" << std::endl;

    dbus_message_unref(msg);
}
