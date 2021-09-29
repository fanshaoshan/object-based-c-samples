#include <stdio.h>
#include <stdlib.h>

#include "device.h"


int modbus_open(struct device_t *device)
{
    printf("modbus open\n");
    return 0;
}

int modbus_read_register(struct device_t *device, int addr)
{
    printf("modbus read: %d\n", addr);
    return addr;
}


struct device_ops_t modbus_ops = {
    .open = modbus_open,
    .read_register = modbus_read_register
}; 
