cmake_minimum_required(VERSION 3.0)

#set(CMAKE_MODULE_PAT ${CMAKE_CURRENT_SOURCEDIR}/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(QWT_INCLUDE_DIR)


project(VEML6030rpiV1 VERSION 1.7.3 LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(VEMLtest.out demoVEML6030rpi.cpp CppTimer.h VEML6030rpi.cpp VEML6030rpi.h Iir.h )

find_library(wiringPi_LIB wiringPi)

find_library(mman_LIB rt)

find_package(iir)
#target_link_libraries(... iir::iir)

target_link_libraries( VEMLtest.out ${wiringPi_LIB} ${mman_LIB} iir::iir_static Qt5::Widgets)

#qt5_use_modules(Widgets) 
#qt5_add_resources