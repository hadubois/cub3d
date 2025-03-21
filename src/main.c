#include "cube3d.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (WRONG_NUMBER_ARG, 1);
	ft_bzero(&data, sizeof(t_data));
	//printf("%s\n", data.ea);
	if (parse(av[1], &data) == false)
		return (1);
	free_data(&data);
	return (0);
}