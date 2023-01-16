#include "so_long.h"

void	ft_set_data(t_data *d)
{
	d->wall = "data/imgs/wall.xpm";
	d->floor = "data/imgs/floor.xpm";
	d->collect = "data/imgs/collect.xpm";
	d->exit = "data/imgs/exit.xpm";
	d->empty = "data/imgs/enemy.xpm";
	d->middle = "data/imgs/middle.xpm";
	d->right = "data/imgs/right.xpm";
	d->left = "data/imgs/left.xpm";
	d->up = "data/imgs/up.xpm";
	d->down = "data/imgs/down.xpm";
	d->lost = "data/imgs/lost_scene.xpm";
	d->rose = "data/imgs/rose_scene.xpm";
}

int	main(int c, char **v)
{
	t_pdmh		pdmh;

	pdmh.d = malloc(sizeof(t_data));
	pdmh.m = malloc(sizeof(t_map));
	pdmh.h = malloc(sizeof(t_player));
	if (c != 2)
		return (1);
	ft_set_map(pdmh.m, v[1]);
	ft_set_data(pdmh.d);
	ft_open_window(&pdmh);
	ft_play_game(&pdmh);
	usleep(250000);
	ft_close_window(pdmh);
	free(pdmh.d);
	free(pdmh.m);
	free(pdmh.h);
	return (0);
}
