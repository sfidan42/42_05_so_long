#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	int		enemies;
	char	**map;
}			t_map;

typedef struct s_data
{
	char	*wall;
	char	*floor;
	char	*enemy;
	char	*collect;
	char	*exit;
	char	*empty;
	char	*middle;
	char	*right;
	char	*left;
	char	*up;
	char	*down;
	char	*multi;
	char	*lost;
	char	*rose;
	char	*pnl_bg;
	char	*enemy_tomb;
}			t_data;

typedef struct s_player
{
	char	*look;
	int		steps;
	int		loc_x;
	int		loc_y;
	int		old_x;
	int		old_y;
	int		killed;
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

void	ft_put_panel(t_pdmh *pdmh);
void	ft_update_panel(t_pdmh *pdmh);

void	ft_open_window(t_pdmh *pdmh);
void	ft_play_game(t_pdmh *pdmh);
void	ft_close_window(t_pdmh pdmh);

int		key_hook(int keycode, t_pdmh *pdmh);
void	ft_use_player(t_pdmh *pdmh);
void	ft_set_player(t_pdmh *pdmh);
void	ft_playercontrol_move(t_pdmh pdmh);
void	ft_playercontrol_look(t_pdmh pdmh, int k);
void	ft_playercontrol(t_pdmh *pdmh, int key);

void	ft_kill_enemy(t_pdmh *pdmh, int x, int y);

void	ft_init_string(t_string *s, int x, int y, int color);
void	ft_set_string(t_string *s, int x, int y, int color);
void	ft_put_string(t_string s, t_ptr p, char *text, int nbr);

void	ft_game_lost(t_pdmh *pdmh);
void	ft_game_won(t_pdmh *pdmh);

#endif
