
#ifndef SHAPE_H_
#define SHAPE_H_

struct shape_t;

struct shape_ops_t
{
    void (*destroy)(struct shape_t *self);
    void (*draw)(struct shape_t *self);
};

struct shape_t {
    int x;
    int y;
    struct shape_ops_t *ops;
};

void shape_destroy(struct shape_t *self);

void shape_draw(struct shape_t *self);

#endif // SHAPE_H_