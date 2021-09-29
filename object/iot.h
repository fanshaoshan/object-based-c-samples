#ifndef IOT_H
#define IOT_H

struct iot_t;

struct iot_t* iot_create(const char *ip, int port);
void iot_destroy(struct iot_t *self);
void iot_send_message(struct iot_t *self, const char *message);
void iot_update_twin(struct iot_t *self, const char *twin);

#endif
