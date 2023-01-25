#include "../so_long_bonus.h"

void	ft_init_string(t_string *s, int x, int y, int color)
{
	s->x = x;
	s->y = y;
	s->color = color;
}

void	ft_set_string(t_string *s, int x, int y, int color)
{
	s->x += x;
	s->y += y;
	s->color = color;
}

void	ft_put_string(t_string s, t_ptr p, char *text, int nbr)
{
	int	x;

	mlx_string_put(p.mlx_ptr, p.win_ptr, s.x, s.y, s.color, text);
	x = s.x + ft_strlen(text) * 6;
	text = ft_itoa(nbr);
	mlx_string_put(p.mlx_ptr, p.win_ptr, x, s.y, s.color, text);
	free(text);
}
