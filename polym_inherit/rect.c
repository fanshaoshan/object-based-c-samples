#include <stdio.h>
#include <stdlib.h>
#include "../base.h"
#include "shape.h"
#include "rect.h"

struct rect_t {
    int length;
    int width;
    struct shape_t s_info;
};

// if s_info is not align at the begining of rect_t, use container_of to find
// container structure
static struct rect_t *RECT_I(struct shape_t *s)
 {
	return container_of(s, struct rect_t, s_info);
 }

void rect_destroy(struct shape_t *s)
{
    printf("rect destroy\n");
    free(RECT_I(s));
}

void rect_draw(struct shape_t *s)
{
    struct rect_t *r = RECT_I(s);
    printf("rect [%d, %d] @ (%d, %d)\n", r->length, r->width, s->x, s->y);
}

static struct shape_ops_t rect_ops = {
    rect_destroy,
    rect_draw,
};  


struct shape_t * rect_create(int width, int length)
{
    printf("rect create\n");  
    struct rect_t *r = malloc(sizeof(struct rect_t));
    r->s_info.ops = &rect_ops;
    r->s_info.x = r->s_info.y = 10;
    r->width = width;
    r->length = length;
    return &r->s_info;
}