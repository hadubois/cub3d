#include "cube3d.h"

void	print_back(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < 900)
	{
		j = -1;
		while (++j < 1600)
		{
			if (i < 450)
				my_pixel_put(j, i, data, PASTEL_GREEN);
			else 
				my_pixel_put(j, i, data, PASTEL_BLUE);
		}
	}
}

void	print_line(t_data *data, int i, float r, int color)
{
	int len;

	len = -1;
	while (++len < SC_HEI / r * 20)
		my_pixel_put(i, SC_HEI / 2 + len, data, color);
	len = -1;
	while (++len < SC_HEI / r * 20)
		my_pixel_put(i, SC_HEI / 2 - len, data, color);
}

void	print_ray(t_data *data)
{
	float r;
	t_ray ray;
	float fov;

	fov = -1 * M_PI / 8;
	ray.i = -1;
	while (++ray.i < SC_WID)
	{
		r = 0;
		while (1)
		{
			if (r)
			{
				ray.prev.x = ray.ray.x;
				ray.prev.y = ray.ray.y;
			}
			ray.ray.x = data->player.x - cos(data->player_angle + fov) * r;
			ray.ray.y = data->player.y - sin(data->player_angle + fov) * r;
			//mlx_pixel_put(data->mlx, data->win, ray.x, ray.y, data->f[0] << 16 | data->f[1] << 8 | data->f[2]);
			if (!((ray.ray.x + 1) % 64 && (ray.ray.y + 1) % 64 && ray.ray.x % 64 && ray.ray.y  % 64) && (data->map[ray.ray.y / 64][ray.ray.x / 64] == '1'))
				break;
			r += 1;
		}

		if (ray.prev.x / 64 > ray.ray.x / 64 && (ray.ray.x + 1) % 64 == 0)
			print_line(data, ray.i, r, PASTEL_ORANGE);
		else if (ray.prev.y / 64 > ray.ray.y / 64 && (ray.ray.y + 1) % 64 == 0)
			print_line(data, ray.i, r, PASTEL_PINK);
		else if (ray.prev.x / 64 < ray.ray.x / 64 && (ray.ray.x) % 64 == 0)
			print_line(data, ray.i, r, PASTEL_YELLOW);
		else if (ray.prev.y / 64 < ray.ray.y / 64 && (ray.ray.y) % 64 == 0)
			print_line(data, ray.i, r, PASTEL_BROWN);
		fov += M_PI / 3 / SC_WID;
	}
}
