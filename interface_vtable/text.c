#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../base.h"
#include "drawable.h"

struct text_t {
    struct drawable_t drawable;
    char *txt;
};

static void text_draw(struct drawable_t *d, int x, int y)
{
    struct text_t *this = container_of(d, struct text_t, drawable);
    printf("txt[%s] @(%d, %d)\n", this->txt, x, y);
}

static const struct drawable_ops_t text_drawable_ops = {
    .draw = text_draw
};

struct text_t *text_create(const char* txt)
{
    struct text_t *this = malloc(sizeof(struct text_t));
    this->txt = strdup(txt);
    this->drawable.ops = &text_drawable_ops;
}

void text_destroy(struct text_t *this)
{
    free(this->txt);
    free(this);
}

void text_set(struct text_t *this, const char* txt)
{
    if (this->txt)
       free(this->txt);
    this->txt = strdup(txt);
}

const char *text_get(struct text_t *this)
{
    return this->txt;
}


struct drawable_t *text_get_drawable(struct text_t *this)
{
    return &this->drawable;
}