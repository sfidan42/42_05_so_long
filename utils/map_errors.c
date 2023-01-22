#include "../so_long.h"

int	ft_collectibles(t_map m, int i, int j)
{
	int	item;

	if (i < 0 || j < 0 || i > m.size_x || j > m.size_y)
		return (0);
	if (m.map[i][j] == '1')
		return (0);
	if (m.map[i][j] == '2')
		return (0);
	item = m.map[i][j] == 'c';
	m.map[i][j] = '2';
	if (item)
		return (1
			+ ft_collectibles(m, i + 1, j)
			+ ft_collectibles(m, i - 1, j)
			+ ft_collectibles(m, i, j + 1)
			+ ft_collectibles(m, i, j - 1));
	return (0);
}

char	**ft_check_map(t_pdmh pdmh)
{
	if (!pdmh.m->size_x)
		ft_printf("Error! The map is empty!\n");
	else if (ft_collectibles(*pdmh.m, pdmh.h->loc_x, pdmh.h->loc_y) - pdmh.m->items)
		ft_printf("Error! There are item(s) cannot be collected!\n");
	else if (ft_map_misshapen(pdmh.m->map))
		ft_printf("Error! The map is not rectangular!\n");
	else if (ft_map_uninclosed(pdmh.m->map))
		ft_printf("Error! The map is not surrounded by walls!\n");
	else if (ft_map_objects(pdmh.m->map))
		return (pdmh.m->map);
	ft_free_map(pdmh.m->map);
	exit(0);
}
