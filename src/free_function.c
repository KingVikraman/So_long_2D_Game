#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static	void	clear_images(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

static	void	destroy_images(t_game *game)
{
	clear_images(game->mlx, game->img_idle);
	clear_images(game->mlx, game->img_wall);
	clear_images(game->mlx, game->img_floor);
	clear_images(game->mlx, game->img_chest_closed);
	clear_images(game->mlx, game->img_chest_open);
	clear_images(game->mlx, game->img_exit_closed);
	clear_images(game->mlx, game->img_exit_open);
	clear_images(game->mlx, game->img_run_up_1);
	clear_images(game->mlx, game->img_run_up_2);
	clear_images(game->mlx, game->img_run_down_1);
	clear_images(game->mlx, game->img_run_down_2);
	clear_images(game->mlx, game->img_run_left_1);
	clear_images(game->mlx, game->img_run_left_2);
	clear_images(game->mlx, game->img_run_right_1);
	clear_images(game->mlx, game->img_run_right_2);
}

static	void	free_collected_flags(t_game *game)
{
	int	i;

	if (!game->collected_flags)
		return ;
	i = 0;
	while (i < game->height)
		free(game->collected_flags[i++]);
	free(game->collected_flags);
}

static	void	destroy_window_and_mlx(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_resources(t_game *game)
{
	destroy_images(game);
	free_map(game->map);
	free_collected_flags(game);
	destroy_window_and_mlx(game);
}
