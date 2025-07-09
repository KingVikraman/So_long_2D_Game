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