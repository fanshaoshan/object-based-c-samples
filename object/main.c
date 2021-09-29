#include <stdio.h>
#include <stdlib.h>

#include "iot.h"

int main()
{
    // demo object
    struct iot_t *iot = iot_create("192.168.1.108", 5020);
    iot_send_message(iot, "hello");
    iot_send_message(iot, "bye");
    iot_destroy(iot);

    return 0;
}