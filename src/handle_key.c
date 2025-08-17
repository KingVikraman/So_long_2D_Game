#include "../includes/so_long.h"

int	handle_key(int keycode, t_game *game);

static	void	update_moves(t_game *game)
{
	game->is_idle = 0;
	gettimeofday(&game->last_input_time, NULL);
}

static	void	handle_movement(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
	{
		update_moves(game);
		move_player(game, -1, 0);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		update_moves(game);
		move_player(game, 1, 0);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		update_moves(game);
		move_player(game, 0, -1);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		update_moves(game);
		move_player(game, 0, 1);
	}
}

int	handle_key(int keycode, t_game *game)
{
	gettimeofday(&game->last_input_time, NULL);
	if (keycode == 65307)
		close_window(game);
	else
		handle_movement(keycode, game);
	return (0);
}
