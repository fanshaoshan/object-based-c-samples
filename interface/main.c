#include <stdio.h>

#include "drawable.h"
#include "text.h"

int main()
{
    struct text_t *t1 = text_create("hello");
    text_set(t1, "World");
    
    struct drawable_t *td = text_get_drawable(t1);
    td->draw(td, 10, 10);

    text_destroy(t1);
    return 0;
}