#include "../so_long_bonus.h"

void	ft_put_img(t_ptr p, char *file_name, int x, int y)
{
	int		img_w;
	int		img_h;

	p.img_ptr = mlx_xpm_file_to_image(p.mlx_ptr, file_name, &img_w, &img_h);
	mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img_ptr, x, y);
}

void	ft_open_window(t_pdmh *pdmh)
{
	pdmh->p.mlx_ptr = mlx_init();
	pdmh->p.win_ptr = mlx_new_window(pdmh->p.mlx_ptr,
			pdmh->m->size_x, pdmh->m->size_y, "knight fights");
}

void	ft_close_window(t_pdmh pdmh)
{
	mlx_destroy_window(pdmh.p.mlx_ptr, pdmh.p.win_ptr);
	ft_free_map(pdmh.m->map);
	free(pdmh.d);
	free(pdmh.m);
	free(pdmh.h);
}
