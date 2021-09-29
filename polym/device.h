
#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

struct device_t;

enum {
    MODBUS,
    BACNET
};

struct device_ops_t
{
    int (*open)(struct device_t *self);
    int (*read_register)(struct device_t *self, int addr);
};

struct device_t {
    char *name;
    int type;
    struct device_ops_t *ops;
};


struct device_t *device_create(const char* name, int type);
void device_destroy(struct device_t *this);

int device_open(struct device_t *this);
uint16_t device_read_register(struct device_t *this, int addr);

#endif // DEVICE_H