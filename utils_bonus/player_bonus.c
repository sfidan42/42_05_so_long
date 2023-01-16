#include "../so_long_bonus.h"

int	key_hook(int keycode, t_pdmh *pdmh)
{
	if (keycode == 'q' || keycode == 65307)
		mlx_loop_end(pdmh->p.mlx_ptr);
	ft_playercontrol(pdmh, keycode);
	return (0);
}

void	ft_use_player(t_pdmh *pdmh)
{
	mlx_key_hook(pdmh->p.win_ptr, key_hook, pdmh);
	mlx_loop(pdmh->p.mlx_ptr);
}

void	ft_set_player(t_pdmh *pdmh)
{
	int	i;
	int	j;

	pdmh->h->steps = 0;
	pdmh->h->killed = 0;
	pdmh->h->collected = 0;
	pdmh->h->look = pdmh->d->middle;
	i = 0;
	while (pdmh->m->map[i])
	{
		j = 0;
		while (pdmh->m->map[i][j])
		{
			if (ft_tolower(pdmh->m->map[i][j]) == 'p')
			{
				pdmh->h->loc_x = i;
				pdmh->h->old_x = i;
				pdmh->h->loc_y = j;
				pdmh->h->old_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_kill_enemy(t_pdmh *pdmh, int x, int y)
{
	pdmh->m->map[x][y] = '0';
	ft_put_img(pdmh->p, pdmh->d->enemy_tomb, y * 64, x * 64 + 32);
}
