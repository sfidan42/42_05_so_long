#include "../so_long.h"

void	ft_game_won(t_pdmh *pdmh)
{
	ft_put_img(pdmh->p, pdmh->d->rose,
		pdmh->m->size_x / 2 - 144, pdmh->m->size_y / 2 - 192);
	sleep(1);
	ft_printf("Queen is honored of your fight!\n");
	ft_close_window(*pdmh);
	exit(0);
}
