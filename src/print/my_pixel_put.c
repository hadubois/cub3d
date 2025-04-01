#include "cube3d.h"

void    my_pixel_put(int x, int y, t_data *data, int color)
{
    int offset;

    offset = (y * data->img.size_line) + ((data->img.bpp / 8) * x);
    *(unsigned int *)(data->img.img_pix + offset) = color;
}