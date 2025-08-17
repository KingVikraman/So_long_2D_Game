#include "../includes/so_long.h"

static void	render_wall_or_floor(t_game *game, char c)
{
	int	x;
	int	y;

	x = game->tile_x;
	y = game->tile_y;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
}

static void	render_collectible(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = game->tile_x;
	y = game->tile_y;
	if (game->collected_flags[i][j])
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_chest_open, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_chest_closed, x, y);
}

static void	render_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->tile_x;
	y = game->tile_y;
	if (game->collected == game->total_collectibles)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit_open, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit_closed, x, y);
}

static void	render_tile(t_game *game, char c, int i, int j)
{
	game->tile_x = j * TILE_SIZE;
	game->tile_y = i * TILE_SIZE;
	render_wall_or_floor(game, c);
	if (c == 'C')
		render_collectible(game, i, j);
	else if (c == 'E')
		render_exit(game);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			render_tile(game, game->map[i][j], i, j);
			j++;
		}
		i++;
	}
	draw_player(game);
}
