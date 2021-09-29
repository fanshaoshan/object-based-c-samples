#include <stdio.h>
#include <stdlib.h>

#include "device.h"

int bacnet_open(struct device_t *device)
{
    printf("bacnet open\n");
    return 0;
}

int bacnet_read_register(struct device_t *device, int addr)
{
    printf("bacnet read: %d\n", addr);
    return addr;
}


struct device_ops_t bacnet_ops = {
    .open = bacnet_open,
    .read_register = bacnet_read_register
}; 

