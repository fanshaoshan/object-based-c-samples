#include <stdio.h>
#include <stdlib.h>

#include "device.h"

int main()
{
    struct device_t *devices[2];

    devices[0] = device_create("modbus", MODBUS);
    devices[1] = device_create("bacnet", BACNET);

    for (int i=0; i<2; i++) {
        device_open(devices[i]);
        device_read_register(devices[i], 100);
        device_destroy(devices[i]);
    }

    return 0;
}