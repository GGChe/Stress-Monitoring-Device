cmake_minimum_required(VERSION 3.0)

project(VEML6030rpiV1 VERSION 1.7.3 LANGUAGES CXX)


add_executable(StressC.out StressController.cpp CppTimer.h VEML6030rpi.cpp VEML6030rpi.h Fir1.h )

find_library(wiringPi_LIB wiringPi)

find_library(mman_LIB rt)

find_package(iir)

target_link_libraries( StressC.out ${wiringPi_LIB} ${mman_LIB} iir::iir_static fir_static)
