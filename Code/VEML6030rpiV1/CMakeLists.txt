cmake_minimum_required(VERSION 3.0)

project(VEML6030rpiV1 VERSION 1.7.3 LANGUAGES CXX)


add_executable(VEMLtest.out demoVEML6030rpi.cpp CppTimer.h VEML6030rpi.cpp VEML6030rpi.h Iir.h )

find_library(wiringPi_LIB wiringPi)

find_library(mman_LIB rt)

find_package(iir)

target_link_libraries( VEMLtest.out ${wiringPi_LIB} ${mman_LIB} iir::iir_static )
