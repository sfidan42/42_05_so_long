#include "../so_long_bonus.h"

char	**ft_check_map(char **map)
{
	if (!**map)
		ft_printf("Error! The map is empty!\n");
	else if (ft_map_misshapen(map))
		ft_printf("Error! The map is not rectangular!\n");
	else if (ft_map_uninclosed(map))
		ft_printf("Error! The map is not surrounded by walls!\n");
	else if (ft_map_objects(map))
		return (map);
	ft_free_map(map);
	exit(0);
}
