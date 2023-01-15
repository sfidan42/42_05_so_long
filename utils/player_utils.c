#include "../so_long.h"

void	ft_player_look(t_pdmh *pdmh, int key)
{
	if (key == 'w' || key == 65362)
		pdmh->h->look = pdmh->d->up;
	else if (key == 'a' || key == 65361)
		pdmh->h->look = pdmh->d->left;
	else if (key == 's' || key == 65364)
		pdmh->h->look = pdmh->d->down;
	else if (key == 'd' || key == 65363)
		pdmh->h->look = pdmh->d->right;
	else if (key == ' ')
		pdmh->h->look = pdmh->d->multi;
	else if (key == 65293)
		pdmh->h->look = pdmh->d->middle;
}

void	ft_special_ability(t_pdmh *pdmh)
{
	static int	i = 1;
	int			x;
	int			y;
	char		**map;

	if (--i)
		return ;
	x = pdmh->h->loc_x;
	y = pdmh->h->loc_y;
	map = pdmh->m->map;
	pdmh->h->killed += (map[x + 1][y] == 'x') + (map[x - 1][y] == 'x')
		+ (map[x][y + 1] == 'x') + (map[x][y - 1] == 'x');
	if (map[x + 1][y] == 'x')
		ft_kill_enemy(pdmh, x + 1, y);
	if (map[x][y + 1] == 'x')
		ft_kill_enemy(pdmh, x, y + 1);
	if (map[x - 1][y] == 'x')
		ft_kill_enemy(pdmh, x - 1, y);
	if (map[x][y - 1] == 'x')
		ft_kill_enemy(pdmh, x, y - 1);
}

typedef struct s_step_var
{
	char	next;
	int		arrow;
	int		wasd;
	int		key;
}			t_step_var;

void	ft_decisions(t_pdmh *pdmh, t_step_var v)
{
	if (v.arrow && v.next == 'x')
	{
		pdmh->h->killed++;
		ft_kill_enemy(pdmh, pdmh->h->loc_x, pdmh->h->loc_y);
	}
	else if (v.wasd && v.next == 'c')
	{
		pdmh->h->collected++;
		pdmh->m->map[pdmh->h->loc_x][pdmh->h->loc_y] = '0';
	}
	if (v.wasd && v.next == 'x')
		ft_game_lost(pdmh);
	if (pdmh->m->items == pdmh->h->collected && v.next == 'e' && v.wasd)
		ft_game_won(pdmh);
}

void	ft_take_step(t_pdmh *pdmh, int k)
{
	t_step_var	v;

	pdmh->h->loc_x -= (k == 'w') + (k == 65362) - (k == 's') - (k == 65364);
	pdmh->h->loc_y -= (k == 'a') + (k == 65361) - (k == 'd') - (k == 65363);
	v.next = pdmh->m->map[pdmh->h->loc_x][pdmh->h->loc_y];
	v.wasd = (k == 'w') + (k == 'a') + (k == 's') + (k == 'd');
	v.arrow = (65361 <= k && k <= 65364);
	ft_decisions(pdmh, v);
	if (k == ' ')
		ft_special_ability(pdmh);
	if (v.next == '1' || v.arrow || v.next == 'e' || k == ' ')
	{
		pdmh->h->loc_y = pdmh->h->old_y;
		pdmh->h->loc_x = pdmh->h->old_x;
	}
	else
		ft_printf("%d\n", pdmh->h->steps++);
}

void	ft_playercontrol(t_pdmh *pdmh, int key)
{
	ft_put_img(pdmh->p, pdmh->d->floor,
		pdmh->h->old_y * 64, pdmh->h->old_x * 64 + 32);
	ft_player_look(pdmh, key);
	ft_take_step(pdmh, key);
	ft_put_img(pdmh->p, pdmh->h->look,
		pdmh->h->loc_y * 64, pdmh->h->loc_x * 64 + 32);
	ft_update_panel(pdmh);
	pdmh->h->old_y = pdmh->h->loc_y;
	pdmh->h->old_x = pdmh->h->loc_x;
}
