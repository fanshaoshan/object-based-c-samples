cmake_minimum_required (VERSION 3.12)
project (polym C)

add_executable(polym main.c device.c modbus.c bacnet.c)