# Проверка версии CMake
cmake_minimum_required(VERSION 2.8)

# Название проекта
project(hello_world)

# Установка переменной
# set(SOURCE main.cpp)

# Расположение заголовочных файлов
# include_directories(./)

# Создаёт исполняемый файл
# add_executable(main ${SOURCE})

# Создание статической/динамической библиотеки
# add_library(lib STATIC/SHARED SOURCE)

# Добавление библиотеки к линковке
# add_library(lib1 STATIC/SHARED IMPORTED)

# Установка параметров
# set_property(main lib1 PROPERTY IMPORTED_LOCATION /lib/lib1.a)
# add_link_librares(${main} lib1)

# Добавление подпроекта
# add_subdirectory(sub)

# Линковка с подпроектом
# target_link_libraries(main sub)

# Ищет библиотеки
# find_package()

# Условные операторы
# if(condition)
# else()
# endif()
