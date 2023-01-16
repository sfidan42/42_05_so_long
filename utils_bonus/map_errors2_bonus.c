#include "../so_long_bonus.h"

int	ft_map_misshapen(char **map)
{
	int	i;

	i = 1;
	while (map[i])
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (1);
	return (0);
}

void	ft_map_uninclosed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (1);
	i = -1;
	while (map[++i])
		if (map[i][0] != 1 || map[i][ft_strlen()] != '1')
			return (1);
	j = 0;
	while (map[i][j])
		if (map[i][j++] != '1')
			return (1);
	return (0);
}

int	ft_map_obj_conditions(int c, int p, int e)
{
	if (c == 0)
		ft_printf("Error! There is no collectable (rose)\n");
	else
		return (0);
	if (p == 0)
		ft_printf("Error! There is no player (warrior)!\n");
	else if (p > 1)
		ft_printf("Error! There are multiple players (warriors)!\n");
	else
		return (0);
	if (e == 0)
		ft_printf("Error! There is no exit (queen)!\n");
	else if (e > 1)
		ft_printf("Error! There can't be multiple exits (queens)!\n");
	else
		return (0);
	return (1);
}

int	ft_map_objects(char **map)
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;

	i = 0;
	j = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c += map[i][j] == 'c';
			p += map[i][j] == 'p';
			e += map[i][j++] == 'e';
		}
		i++;
	}
	return (ft_map_obj_conditions(c, p, e));
}
