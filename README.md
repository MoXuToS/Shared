Для сборки проекта потребуются следующие библиотеки:

· Python.h,
для инициализации интерпретатора Python;

· cstdlib,
для инициализации пространства, в котором ищется файл python framework;

· Boost/python,
для предоставления инструментов для экспорта Python классов в C++.

· dbus python, 
для взаимодействия с шиной dbus.

· Qt, для создания GUI.

· Cmake
для упрощения создание кроссплатформенного проекта (создания связи между QT приложением и API фреймворка, а также для интеграции в проект библиотек Python, Boost/Python).

Для сборки проекта запустите следующий код в консоле

mkdir build   
cd build  
cmake ..  
make

Затем запустите испольняемый файл main.cpp
