#include "../includes/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// void	render_map(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (j < game->width)
// 		{
// 			char	c = game->map[i][j];
// 			int		x = j * TILE_SIZE;
// 			int		y = i * TILE_SIZE;

// 			if (c == '1')
// 				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
// 			else
// 				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
			
// 			if (c == 'C')
// 			{
// 				if (game->collected_flags[i][j])
// 					mlx_put_image_to_window(game->mlx, game->win, game->img_chest_open, x, y);
// 				else
// 					mlx_put_image_to_window(game->mlx, game->win, game->img_chest_closed, x, y);
// 			}
// 			else if (c == 'E')
// 			{
// 				if (game->collected == game->total_collectibles)
// 					mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, x, y);
// 				else
// 					mlx_put_image_to_window(game->mlx, game->win, game->img_exit_closed, x, y);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_player(game);
// }



static void	render_tile(t_game *game, char c, int x, int y, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
	if (c == 'C')
	{
		if (game->collected_flags[i][j])
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_chest_open, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_chest_closed, x, y);
	}
	else if (c == 'E')
	{
		if (game->collected == game->total_collectibles)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_open, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_closed, x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			render_tile(game, game->map[i][j], x, y, i, j);
			j++;
		}
		i++;
	}
	draw_player(game);
}
