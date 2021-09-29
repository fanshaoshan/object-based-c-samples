#include <stdio.h>
#include <stdlib.h>

#include "shape.h"
#include "rect.h"
#include "circle.h"

int main()
{
    struct shape_t *s1 =  rect_create(10, 20);
    shape_draw(s1);
    shape_destroy(s1);

    struct shape_t *c1 = circle_create(100);
    shape_draw(c1);
    shape_destroy(c1);

    return 0;
}