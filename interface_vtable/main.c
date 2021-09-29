#include <stdio.h>

#include "drawable.h"
#include "text.h"

int main()
{
    struct text_t *t = text_create("Hello");
    text_set(t, "World");

    struct drawable_t *d = text_get_drawable(t);
    d->ops->draw(d, 10, 10);

    text_destroy(t);
    return 0;
}



