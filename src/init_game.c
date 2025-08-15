#include "../includes/so_long.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}

void	init_collected_flags(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			game->collected_flags[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	check_collectible(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C' && game->collected_flags[y][x] == 0)
	{
		game->collected_flags[y][x] = 1;
		game->collected++;
	}
}

int	close_window(t_game *game)
{
	free_resources(game);
	exit (0);
	return (0);
}
