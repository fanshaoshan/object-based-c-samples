#ifndef DRAWABLE_H
#define DRAWABLE_H

struct drawable_t;

struct drawable_ops_t {
    void (*draw)(struct drawable_t *d, int x, int y);
};

struct drawable_t {
    const struct drawable_ops_t *ops;
};

#endif