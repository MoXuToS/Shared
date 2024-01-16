import dbus
import dbus.service
from dbus.mainloop.glib import DBusGMainLoop
from gi.repository import Gio

class FileFormatManager:
    def __init__(self):
        DBusGMainLoop(set_as_default=True)
        dbus.mainloop.glib.DBusGMainLoop()
        self.bus = dbus.SessionBus()
        self.service_name = 'com.example.FileFormatManager'
        self.object_path = '/com/example/FileFormatManager'
        self.interface_name = 'com.example.FileFormatManagerInterface'
        self.applications = {}

        # Регистрация сервиса DBus
        self.bus_name = dbus.service.BusName(self.service_name, bus=self.bus)
        self.object = FileFormatManagerObject(self.bus, self.object_path, self)
        self.interface = dbus.service.Interface()

    def register_file_format(self, file_format, application):
        # Регистрация формата файла и связанного с ним приложения
        self.applications[file_format] = application

    def open_file(self, file_path):
        # Открытие файла с использованием зарегистрированного приложения
        file = Gio.File.new_for_path(file_path)
        info = file.query_info('standard::content-type', Gio.FileQueryInfoFlags.NONE, None)
        content_type = info.get_content_type()
        app_info = Gio.AppInfo.get_default_for_type(content_type, True)
        app_info.launch([file], None)

class FileFormatManagerObject(dbus.service.Object):
    def __init__(self, bus, object_path, manager):
        dbus.service.Object.__init__(self, bus, object_path)
        self.manager = manager

    @dbus.service.method(dbus_interface='com.example.FileFormatManagerInterface',
                         in_signature='ss', out_signature='')
    def RegisterFileFormat(self, file_format, application):
        self.manager.register_file_format(file_format, application)

    @dbus.service.method(dbus_interface='com.example.FileFormatManagerInterface',
                         in_signature='s', out_signature='')
    def OpenFile(self, file_path):
        self.manager.open_file(file_path)

