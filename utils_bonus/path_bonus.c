#include "../so_long_bonus.h"

int	ft_items(t_map m, t_player *h)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			c += m.map[i][j] == 'c';
			if (m.map[i][j] == 'p')
			{
				h->loc_x = i;
				h->loc_y = j;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int	ft_collectibles(t_map m, int i, int j)
{
	int	item;

	item = m.map[i][j] == 'c';
	if (i < 0 || j < 0 || i > m.size_x || j > m.size_y)
		return (0);
	if (m.map[i][j] == '1')
		return (0);
	if (m.map[i][j] == '2')
		return (0);
	m.map[i][j] = '2';
	return (item
		+ ft_collectibles(m, i + 1, j)
		+ ft_collectibles(m, i - 1, j)
		+ ft_collectibles(m, i, j + 1)
		+ ft_collectibles(m, i, j - 1));
}

void	ft_check_path(t_pdmh pdmh)
{
	int		items;
	int		collectibles;
	char	**map;

	map = ft_copy_map(*pdmh.m);
	items = ft_items(*pdmh.m, pdmh.h);
	collectibles = ft_collectibles(*pdmh.m, pdmh.h->loc_x, pdmh.h->loc_y);
	ft_free_map(pdmh.m->map);
	pdmh.m->map = map;
	if (collectibles - items && pdmh.h->loc_x && pdmh.h->loc_y)
	{
		ft_free_map(pdmh.m->map);
		ft_printf("Error! There are %d items cannot be collected!\n", items);
		exit(0);
	}
}