#include "../includes/so_long.h"


int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);

	game->win = mlx_new_window(
		game->mlx,
		game->width * 64,
		game->height * 64,
		"So_long"
	);
	if (!game->win)
		return (0);

	return (1);
}

int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	return (0);
}
