#include "../so_long_bonus.h"

void	ft_open_window(t_pdmh *pdmh)
{
	pdmh->p.mlx_ptr = mlx_init();
	pdmh->p.win_ptr = mlx_new_window(pdmh->p.mlx_ptr,
			pdmh->m->size_x, pdmh->m->size_y, "knight fights");
}

void	ft_close_window(t_pdmh pdmh)
{
	int	i;

	i = 0;
	while (pdmh.m->map[i])
		free(pdmh.m->map[i++]);
	free(pdmh.m->map);
	mlx_destroy_window(pdmh.p.mlx_ptr, pdmh.p.win_ptr);
}
