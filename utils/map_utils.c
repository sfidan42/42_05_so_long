#include "../so_long.h"

void	ft_put_item(t_pdmh pdmh, int x, int y, int c)
{
	if (c == '0')
		ft_put_img(pdmh.p, pdmh.d->floor, x, y);
	else if (c == '1')
		ft_put_img(pdmh.p, pdmh.d->wall, x, y);
	else if (ft_tolower(c) == 'c')
		ft_put_img(pdmh.p, pdmh.d->collect, x, y);
	else if (ft_tolower(c) == 'e')
		ft_put_img(pdmh.p, pdmh.d->exit, x, y);
	else if (ft_tolower(c) == 'p')
		ft_put_img(pdmh.p, pdmh.d->middle, x, y);
	else if (ft_tolower(c) == ' ')
		ft_put_img(pdmh.p, pdmh.d->empty, x, y);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
