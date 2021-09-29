#include <stdio.h>
#include <stdlib.h>

#include "../base.h"
#include "shape.h"
#include "circle.h"

struct circle_t {
    struct shape_t s_info;    
    int radius;
};


void circle_destroy(struct shape_t *s)
{
    printf("circle destroy\n");
    free((struct circle_t*)s);
}


void circle_draw(struct shape_t *s)
{
    struct circle_t *c = (struct circle_t*)s;
    printf("circle [%d] @ (%d, %d)\n", c->radius, s->x, s->y);
}


static struct shape_ops_t circle_ops = {
    circle_destroy,
    circle_draw
};

struct shape_t* circle_create(int radius)
{
    printf("circle create\n");
    struct circle_t *c = malloc(sizeof(struct circle_t));
    c->s_info.ops = &circle_ops;
    c->s_info.x = c->s_info.y = 5;
    c->radius = radius;
    return &c->s_info;
}

