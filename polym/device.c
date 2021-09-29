#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "device.h"


extern struct device_ops_t modbus_ops;
extern struct device_ops_t bacnet_ops;

struct device_t *device_create(const char* name, int type)
{
    struct device_t *this = malloc(sizeof(struct device_t));
    this->name = strdup(name);
    this->type = type;
    if (type == MODBUS) {
        this->ops = &modbus_ops;
    } else if (type == BACNET) {
        this->ops = &bacnet_ops;
    }
    return this;
}

void device_destroy(struct device_t *this)
{
    printf("device destroy %s\n", this->name);
    free(this);
}

int device_open(struct device_t *this)
{
    printf("deivce open %s\n", this->name);
    return this->ops->open(this);
}

uint16_t device_read_register(struct device_t *this, int addr)
{
    printf("device read register\n");
    return this->ops->read_register(this, addr);
}
