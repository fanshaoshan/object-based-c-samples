#include <stdio.h>
#include <stdlib.h>

struct point_t {
    int x;
    int y;
};

void point_ctor(struct point_t *this, int x, int y)
{
    this->x = x;
    this->y = y;
}

void point_draw(struct point_t *this)
{
    printf("Point @(%d, %d)\n", this->x, this->y);
}


struct color_point_t {
    struct point_t super;
    int color;
};


struct color_point_t *color_point_ctor(struct color_point_t *this, int x, int y, int c)
{
    point_ctor(&this->super, x, y);
    this->color = c;
}

void color_point_draw(struct color_point_t *this)
{
    printf("color point @(%d, %d), color %d\n", this->super.x, this->super.y, this->color);    
}

int main()
{
    struct point_t p1;
    point_ctor(&p1, 1, 1);
    point_draw(&p1);

    struct color_point_t *cp = malloc(sizeof(struct color_point_t));
    color_point_ctor(cp, 10, 10, 0);
    color_point_draw(cp);
    free(cp);

    return 0;
}