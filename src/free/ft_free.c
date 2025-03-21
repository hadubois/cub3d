#include "cube3d.h"

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	free_data(t_data *data)
{
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free_tab((void **)data->map);
	data = NULL;
}