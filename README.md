Sharing files
=========

Данный репозиторий представляет из себя пример реализации фреймворка обмена данными на основе DBus.

Этот фреймворк на основе DBus разработан для облегчения обмена данными между приложениями на современных операционных системах. Фреймворк предоставляет API для регистрации приложениями поддерживаемых форматов данных и способов запуска, позволяя осуществлять взаимодействие и обмен данными между различными компонентами ПО.

Building and installing the libraries
-----------------------------------

Для работы с фреймоврком потребуется установить библиотеку dbus и cmake.

```bash
sudo apt-get update
sudo apt-get install libdbus-1-dev
sudo apt-get install cmake
```

Start the framework
-----------------------------------

Для запуска фреймворка есть два способа первый из них запустить заранее скомпилированный файл через консоль из каталога проекта.

```bash
$ ./FileManagerDemo
```

Второй способ скомпилировать файл, в случае если вы вносили изменения.

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./FileManagerDemo
```

Start the framework
-----------------------------------

Работа с фреймворком:

```C++
int main()
{
    Manager FileManager;
    FileManager.RegisterFormat("txt");
    return 0;
}
```

В данном примере мы с помощью отправки на шину DBUS сигнала, регистрируем что мы можем работать с форматом txt. Если мы хотим указать, что данный формат можно вызывать/стартовать через определенное приложение, то нужно воспользоваться функцией RegisterOpenType.

```C++
int main()
{
    Manager FileManager;
    FileManager.RegisterOpenFormat("txt", "Notebook);
    return 0;
}
```

В данном примере мы отправляем сигнал на шину dbus с информацией, что Notebook поддерживает открытие txt файлов. 

Для упращения понимания взаимодействия с шиной DBUS данного фреймворка был создан файл FileManager.xml

```xml
<!DOCTYPE busconfig PUBLIC "-//freedesktop//DTD D-BUS Bus Configuration 1.0//EN"
 "http://www.freedesktop.org/standards/dbus/1.0/busconfig.dtd">
<busconfig>
  <service name="com.example.filemanager">
    <interface name="com.example.filemanagerinterface">
      <method name="RegisterFormat">
        <arg type="s" direction="in" name="format"/>
      </method>
      <method name="RegisterOpenType">
        <arg type="as" direction="in" name="RegisterOpenType"/>
      </method>
    </interface>
  </service>
</busconfig>
```

Здесь описаны два метода:

1. RegisterFormat - на шину Dbus поступает информация о формате передаваемых в системе.

2. RegisterOpenType - на шину Dbus поступает массив строк соддержащий в себе формат и приложение для данного формата.

Данный фреймворк ничего не записывает и не сохраняет, а лишь отправляет на шину dbus сигналы, которые целевое приложение должно принять и обработать.
