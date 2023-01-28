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

int	ft_exit_gate(t_map m, int i, int j)
{
	int	gate;

	gate = m.map[i][j] == 'e';
	if (i < 0 || j < 0 || i > m.size_x || j > m.size_y)
		return (0);
	if (m.map[i][j] == '1')
		return (0);
	if (m.map[i][j] == '2')
		return (0);
	m.map[i][j] = '2';
	return (gate
		+ ft_exit_gate(m, i + 1, j)
		+ ft_exit_gate(m, i - 1, j)
		+ ft_exit_gate(m, i, j + 1)
		+ ft_exit_gate(m, i, j - 1));
}

void	ft_check_path(t_pdmh pdmh)
{
	int		items;
	int		collectibles;
	int		exit_gate;
	char	**temp;

	items = ft_items(*pdmh.m, pdmh.h);
	temp = ft_copy_map(*pdmh.m);
	exit_gate = ft_exit_gate(*pdmh.m, pdmh.h->loc_x, pdmh.h->loc_y);
	ft_free_map(pdmh.m->map);
	pdmh.m->map = temp;
	temp = ft_copy_map(*pdmh.m);
	collectibles = ft_collectibles(*pdmh.m, pdmh.h->loc_x, pdmh.h->loc_y);
	ft_free_map(pdmh.m->map);
	pdmh.m->map = temp;
	if (items - collectibles && pdmh.h->loc_x && pdmh.h->loc_y)
	{
		ft_free_map(temp);
		ft_printf("Error! There are %d items cannot be collected!\n", items);
		exit(0);
	}
	if (exit_gate != 1 && pdmh.h->loc_x && pdmh.h->loc_y)
	{
		ft_free_map(temp);
		ft_printf("Error! The player(warrior) reach not the exit(queen)!\n");
		exit(0);
	}
}
