#include "../so_long_bonus.h"

void	ft_put_img(t_ptr p, char *file_name, int x, int y)
{
	int		img_w;
	int		img_h;

	p.img_ptr = mlx_xpm_file_to_image(p.mlx_ptr, file_name, &img_w, &img_h);
	mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img_ptr, x, y);
}

typedef struct s_read_map_elems
{
	char	*map;
	char	*tmp;
	char	*buf;
	int		fd;
	int		b;
}			t_read_map_elems;

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

typedef struct s_xyc
{
	int		x;
	int		y;
	char	c;
}			t_xyc;

void	ft_put_item(t_pdmh pdmh, t_xyc k)
{
	if (k.c == '0')
		ft_put_img(pdmh.p, pdmh.d->floor, k.x, k.y);
	else if (k.c == '1')
		ft_put_img(pdmh.p, pdmh.d->wall, k.x, k.y);
	else if (ft_tolower(k.c) == 'x')
		ft_put_img(pdmh.p, pdmh.d->enemy, k.x, k.y);
	else if (ft_tolower(k.c) == 'c')
		ft_put_img(pdmh.p, pdmh.d->collect, k.x, k.y);
	else if (ft_tolower(k.c) == 'e')
		ft_put_img(pdmh.p, pdmh.d->exit, k.x, k.y);
	else if (ft_tolower(k.c) == 'p')
		ft_put_img(pdmh.p, pdmh.d->middle, k.x, k.y);
	else if (ft_tolower(k.c) == ' ')
		ft_put_img(pdmh.p, pdmh.d->empty, k.x, k.y);
}

void	ft_put_map(t_pdmh *pdmh)
{
	int		i;
	int		j;
	t_xyc	k;

	j = 0;
	while (pdmh->m->map[j])
	{
		i = 0;
		while (pdmh->m->map[j][i])
		{
			k.c = pdmh->m->map[j][i];
			k.x = i * 64;
			k.y = j * 64 + 32;
			ft_put_item(*pdmh, k);
			if (pdmh->m->map[j][i] == 'x')
				pdmh->m->enemies++;
			if (pdmh->m->map[j][i] == 'c')
				pdmh->m->items++;
			i++;
		}
		j++;
	}
}
