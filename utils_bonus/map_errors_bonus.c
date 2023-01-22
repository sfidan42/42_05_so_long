#include "../so_long.h"

int	ft_items(t_map m, t_player *h)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	h->loc_x = 0;
	h->loc_y = 0;
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

char	**ft_check_map(t_pdmh pdmh)
{
	t_map		m;
	t_player	h;
	int			items;

	m = *pdmh.m;
	h = *pdmh.h;
	items = ft_items(m, &h);
	if (!pdmh.m->size_x)
		ft_printf("Error! The map is empty!\n");
	else if (ft_collectibles(m, h.loc_x, h.loc_y) - items && h.loc_x && h.loc_y)
		ft_printf("Error! There are %d items cannot be collected!\n", items);
	else if (ft_map_misshapen(m.map))
		ft_printf("Error! The map is not rectangular!\n");
	else if (ft_map_uninclosed(m.map))
		ft_printf("Error! The map is not surrounded by walls!\n");
	else if (ft_map_objects(m.map))
		return (m.map);
	ft_free_map(m.map);
	exit(0);
}
