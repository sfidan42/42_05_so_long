#include "../so_long_bonus.h"

void	ft_play_game(t_pdmh *pdmh)
{
	ft_put_panel(pdmh);
	ft_put_map(pdmh);
	ft_set_player(pdmh);
	ft_use_player(pdmh);
}
