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
	while (++len < SC_HEI / r * 10)
		my_pixel_put(i, SC_HEI / 2 + len, data, color);
	len = -1;
	while (++len < SC_HEI / r * 10)
		my_pixel_put(i, SC_HEI / 2 - len, data, color);
}

void	print_ray(t_data *data)
{
	float r;
	int ray_x;
	int ray_y;
	float fov;
	int i;

	fov = -1 * M_PI / 8;
	i = -1;
	while (++i < SC_WID)
	{
		r = 0;
		while (1)
		{
			ray_x = data->player.x - cos(data->player_angle + fov) * r;
			ray_y = data->player.y - sin(data->player_angle + fov) * r;
			//mlx_pixel_put(data->mlx, data->win, ray_x, ray_y, data->f[0] << 16 | data->f[1] << 8 | data->f[2]);
			if (!((ray_x + 1) % 32 && (ray_y + 1) % 32 && ray_x % 32 && ray_y  % 32) && (data->map[ray_y / 32][ray_x / 32] == '1'))
				break;
			r += 0.1;
		}
		if ((ray_x + 1) % 32 == 0)
			print_line(data, i, r, PASTEL_ORANGE);
		else if ((ray_y + 1) % 32 == 0)
			print_line(data, i, r, PASTEL_PINK);
		else if ((ray_x) % 32 == 0)
			print_line(data, i, r, PASTEL_YELLOW);
		else if ((ray_y) % 32 == 0)
			print_line(data, i, r, PASTEL_PURPLE);
		fov += M_PI / 4 / SC_WID;
	}
}
