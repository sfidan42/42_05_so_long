#include "../so_long.h"

void	ft_player_look(t_pdmh *pdmh, int key)
{
	if (key == 'w')
		pdmh->h->look = pdmh->d->up;
	else if (key == 'a')
		pdmh->h->look = pdmh->d->left;
	else if (key == 's')
		pdmh->h->look = pdmh->d->down;
	else if (key == 'd')
		pdmh->h->look = pdmh->d->right;
	else if (key == 65293)
		pdmh->h->look = pdmh->d->middle;
}

void	ft_decisions(t_pdmh *pdmh, t_step_var v)
{
	if (v.wasd && v.next == 'c')
	{
		pdmh->h->collected++;
		pdmh->m->map[pdmh->h->loc_x][pdmh->h->loc_y] = '0';
	}
	if (pdmh->m->items == pdmh->h->collected && v.next == 'e' && v.wasd)
		ft_game_won(pdmh);
}

void	ft_take_step(t_pdmh *pdmh, int k)
{
	t_step_var	v;

	pdmh->h->loc_x -= (k == 'w') - (k == 's');
	pdmh->h->loc_y -= (k == 'a') - (k == 'd');
	v.next = pdmh->m->map[pdmh->h->loc_x][pdmh->h->loc_y];
	v.wasd = (k == 'w') + (k == 'a') + (k == 's') + (k == 'd');
	ft_decisions(pdmh, v);
	if (v.next == '1' || v.next == 'e')
	{
		pdmh->h->loc_y = pdmh->h->old_y;
		pdmh->h->loc_x = pdmh->h->old_x;
	}
}

void	ft_playercontrol(t_pdmh *pdmh, int key)
{
	ft_put_img(pdmh->p, pdmh->d->floor,
		pdmh->h->old_y * 64, pdmh->h->old_x * 64);
	ft_player_look(pdmh, key);
	ft_take_step(pdmh, key);
	ft_put_img(pdmh->p, pdmh->h->look,
		pdmh->h->loc_y * 64, pdmh->h->loc_x * 64);
	if (pdmh->h->old_y != pdmh->h->loc_y || pdmh->h->old_x != pdmh->h->loc_x)
	{
		ft_printf("%d\n", pdmh->h->steps++);
		pdmh->h->old_y = pdmh->h->loc_y;
		pdmh->h->old_x = pdmh->h->loc_x;
	}
}
