#ifndef DRAWABLE_H
#define DRAWABLE_H

struct drawable_t {
    void (*draw)(struct drawable_t *d, int x, int y);
};

#endif