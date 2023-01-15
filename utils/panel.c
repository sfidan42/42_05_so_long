#include "../so_long.h"

void	ft_put_panel(t_pdmh *pdmh)
{
	int	i;

	i = 0;
	while (i < pdmh->m->size_x)
	{
		ft_put_img(pdmh->p, pdmh->d->pnl_bg, i, 0);
		i += 64;
	}
}

void	ft_update_panel(t_pdmh *pdmh)
{
	t_string	s;

	ft_put_panel(pdmh);
	ft_init_string(&s, (pdmh->m->size_x - 5 * 64) / 2, 12, 0xFF0000);
	ft_put_string(s, pdmh->p, "enemies alive: ",
		pdmh->m->enemies - pdmh->h->killed);
	ft_set_string(&s, 0, 12, 0xFF0000);
	ft_put_string(s, pdmh->p, "enemies killed: ", pdmh->h->killed);
	ft_set_string(&s, 128, -6, 0x00FF00);
	ft_put_string(s, pdmh->p, "steps: ", pdmh->h->steps);
	ft_set_string(&s, 64, -6, 0x0000FF);
	ft_put_string(s, pdmh->p, "items remaining: ",
		pdmh->m->items - pdmh->h->collected);
	ft_set_string(&s, 0, 12, 0x0000FF);
	ft_put_string(s, pdmh->p, "items collected: ", pdmh->h->collected);
}
