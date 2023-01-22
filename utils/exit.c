#include "../so_long.h"

void	ft_game_won(t_pdmh *pdmh)
{
	ft_put_img(pdmh->p, pdmh->d->rose,
		pdmh->m->size_x / 2 - 144, pdmh->m->size_y / 2 - 192);
	ft_printf("%d\n", pdmh->h->steps++);
	sleep(1);
	ft_printf("Queen is grateful for your roses!\n");
	ft_close_window(*pdmh);
	exit(0);
}
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_all(t_pdmh pdmh)
{
	ft_free_map(pdmh.m->map);
	free(pdmh.d);
	free(pdmh.m);
	free(pdmh.h);
}