#include "../so_long.h"

char	*ft_read_map(char *map_name)
{
	t_read_map_elems	r;

	r.fd = open(map_name, O_RDONLY, 0777);
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
	close(r.fd);
	return (r.map);
}

void	ft_set_map(t_map *m, char *map_name)
{
	char	*xx;

	xx = ft_read_map(map_name);
	m->map = ft_split(xx, '\n');
	free(xx);
	m->size_x = ft_strlen(*m->map);
	m->size_y = 0;
	while (m->map[m->size_y])
		m->size_y++;
	m->size_x *= 64;
	m->size_y *= 64;
}

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
			ft_put_item(*pdmh, i * 64, j * 64, pdmh->m->map[j][i]);
			if (pdmh->m->map[j][i] == 'c')
				pdmh->m->items++;
			i++;
		}
		j++;
	}
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}