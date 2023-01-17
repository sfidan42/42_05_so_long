#include "../so_long_bonus.h"

char	*ft_read_map(char *map_name)
{
	t_read_map_elems	r;

	r.fd = open(map_name, O_RDONLY, 0777);
	if (r.fd == -1)
		exit(0);
	r.buf = malloc(BUFFER_SIZE + 1);
	if (!r.buf)
		return (0);
	r.map = ft_strdup("");
	r.b = 1;
	while (r.b)
	{
		r.b = read(r.fd, r.buf, BUFFER_SIZE);
		if (r.b == -1)
		{
			free(r.map);
			return (0);
		}
		r.buf[r.b] = 0;
		r.tmp = ft_strjoin(r.map, r.buf);
		free(r.map);
		r.map = r.tmp;
	}
	free(r.buf);
	return (r.map);
}

void	ft_set_map(t_map *m, char *map_name)
{
	char	*map;
	int		i;

	map = ft_read_map(map_name);
	i = ft_strlen(map) - 1;
	while (map[i - 1] == '\n')
		map[i--] = 0;
	ft_check_empty_line(map);
	m->map = ft_split(map, '\n');
	free(map);
	m->size_x = 0;
	m->size_y = 0;
	if (*m->map)
		m->size_x = ft_strlen(*m->map);
	while (m->map[m->size_y])
		m->size_y++;
	m->size_x *= 64;
	m->size_y *= 64;
}

void	ft_put_map(t_pdmh *pdmh)
{
	int		i;
	int		j;

	j = 0;
	while (pdmh->m->map[j])
	{
		i = 0;
		while (pdmh->m->map[j][i])
		{
			ft_put_item(*pdmh, i * 64, j * 64 + 32, pdmh->m->map[j][i]);
			if (pdmh->m->map[j][i] == 'c')
				pdmh->m->items++;
			if (pdmh->m->map[j][i] == 'x')
				pdmh->m->enemies++;
			i++;
		}
		j++;
	}
}
