#include "../so_long.h"

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
	t_player	h;
	t_map		m;
	char		**map;
	int			items;
	int			collectibles;

	h = *pdmh.h;
	m = *pdmh.m;
	map = ft_copy_map(*pdmh.m);
	items = pdmh.m->items;
	collectibles = ft_collectibles(m, h.loc_x, h.loc_y);
	ft_free_map(m.map);
	if (collectibles - items)
	{
		ft_free_map(map);
		ft_printf("Error! There are %d items cannot be collected!\n", items);
		exit(0);
	}
	m.map = map;
}
