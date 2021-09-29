#ifndef TEXT_H
#define TEXT_H

struct drawable_t;
struct text_t;

struct text_t *text_create(const char* txt);

void text_destroy(struct text_t *this);

void text_set(struct text_t *this, const char* txt);

const char *text_get(struct text_t *this);

struct drawable_t *text_get_drawable(struct text_t *this);

#endif