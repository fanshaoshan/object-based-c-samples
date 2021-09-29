#include "shape.h"

void shape_destroy(struct shape_t *self)
{
    self->ops->destroy(self);
}

void shape_draw(struct shape_t *self)
{
    self->ops->draw(self);
}
