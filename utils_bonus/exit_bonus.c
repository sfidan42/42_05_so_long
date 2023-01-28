#include "../so_long_bonus.h"

void	ft_game_won(t_pdmh *pdmh)
{
	ft_put_img(pdmh->p, pdmh->d->rose,
		pdmh->m->size_x / 2 - 144, pdmh->m->size_y / 2 - 192);
	ft_printf("%d\n", pdmh->h->steps++);
	ft_update_panel(pdmh);
	sleep(1);
	ft_printf("Queen is honored of your fight!\n");
	ft_close_window(*pdmh);
	exit(0);
}

void	ft_game_lost(t_pdmh *pdmh)
{
	ft_printf("You are killed by a dark knight!\n");
	ft_put_img(pdmh->p, pdmh->d->lost,
		pdmh->m->size_x / 2 - 64, pdmh->m->size_y / 2 - 96);
	ft_update_panel(pdmh);
	sleep(1);
	ft_close_window(*pdmh);
	exit(0);
}
