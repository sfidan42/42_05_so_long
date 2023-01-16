#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include "include/ft_printf/ft_printf.h"
# include "include/libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}			t_ptr;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		items;
	char	**map;
}			t_map;

typedef struct s_data
{
	char	*wall;
	char	*floor;
	char	*collect;
	char	*exit;
	char	*empty;
	char	*middle;
	char	*right;
	char	*left;
	char	*up;
	char	*down;
	char	*lost;
	char	*rose;
}			t_data;

typedef struct s_player
{
	char	*look;
	int		steps;
	int		loc_x;
	int		loc_y;
	int		old_x;
	int		old_y;
	int		collected;
}			t_player;

typedef struct s_string
{
	int		x;
	int		y;
	int		color;
}			t_string;

typedef struct s_pdmh
{
	t_ptr		p;
	t_data		*d;
	t_map		*m;
	t_player	*h;
}				t_pdmh;

void	ft_put_img(t_ptr p, char *file_name, int x, int y);

void	ft_set_map(t_map *m, char *map_name);
void	ft_put_map(t_pdmh *pdmh);

void	ft_open_window(t_pdmh *pdmh);
void	ft_play_game(t_pdmh *pdmh);
void	ft_close_window(t_pdmh pdmh);

int		key_hook(int keycode, t_pdmh *pdmh);
void	ft_use_player(t_pdmh *pdmh);
void	ft_set_player(t_pdmh *pdmh);
void	ft_playercontrol_move(t_pdmh pdmh);
void	ft_playercontrol_look(t_pdmh pdmh, int k);
void	ft_playercontrol(t_pdmh *pdmh, int key);

void	ft_game_won(t_pdmh *pdmh);

typedef struct s_step_var
{
	char	next;
	int		arrow;
	int		wasd;
	int		key;
}			t_step_var;

typedef struct s_read_map_elems
{
	char	*map;
	char	*tmp;
	char	*buf;
	int		fd;
	int		b;
}			t_read_map_elems;

#endif
