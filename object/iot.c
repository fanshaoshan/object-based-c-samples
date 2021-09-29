#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iot.h"

struct iot_t {
    char *ip;
    int port;
};

struct iot_t* iot_create(const char *ip, int port)
{    
    if (port < 0) {
        return NULL;
    }
    struct iot_t *iot = malloc(sizeof(struct iot_t));
    iot->ip = strdup(ip);
    iot->port = port;
    printf("connect to %s:%d\n", ip, port);
    return iot;
}

void iot_destroy(struct iot_t *self)
{
    printf("close connection to %s:%d\n", self->ip, self->port);
    free(self->ip);
    free(self);
}

void iot_send_message(struct iot_t *self, const char *message)
{
    printf("send [%s] to [%s:%d]\n", message, self->ip, self->port);
}

void iot_update_twin(struct iot_t *self, const char *twin)
{
    printf("update [%s] to [%s:%d]\n", twin, self->ip, self->port);
}

