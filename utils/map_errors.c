#include "../so_long.h"

char	**ft_check_map(t_pdmh pdmh)
{
	t_map		m;

	m = *pdmh.m;
	if (!m.size_x)
		ft_printf("Error! The map is empty!\n");
	else if (ft_map_misshapen(m.map))
		ft_printf("Error! The map is not rectangular!\n");
	else if (ft_map_uninclosed(m.map))
		ft_printf("Error! The map is not surrounded by walls!\n");
	else if (ft_map_objects(m.map))
		return (m.map);
	ft_free_map(m.map);
	exit(0);
}
