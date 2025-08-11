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


void	free_resources(t_game *game)
{
	int	i;

	if (game->img_idle)
		mlx_destroy_image(game->mlx, game->img_idle);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_chest_closed)
		mlx_destroy_image(game->mlx, game->img_chest_closed);
	if (game->img_chest_open)
		mlx_destroy_image(game->mlx, game->img_chest_open);
	if (game->img_exit_closed)
		mlx_destroy_image(game->mlx, game->img_exit_closed);
	if (game->img_exit_open) 
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_run_up_1)
		mlx_destroy_image(game->mlx, game->img_run_up_1);
	if (game->img_run_up_2)
		mlx_destroy_image(game->mlx, game->img_run_up_2);
	if (game->img_run_down_1)
		mlx_destroy_image(game->mlx, game->img_run_down_1);
	if (game->img_run_down_2)
		mlx_destroy_image(game->mlx, game->img_run_down_2);
	if (game->img_run_left_1)
		mlx_destroy_image(game->mlx, game->img_run_left_1);
	if (game->img_run_left_2)
		mlx_destroy_image(game->mlx, game->img_run_left_2);
	if (game->img_run_right_1)
		mlx_destroy_image(game->mlx, game->img_run_right_1);
	if (game->img_run_right_2)
		mlx_destroy_image(game->mlx, game->img_run_right_2);
	
	free_map(game->map);
	if (game->collected_flags)
	{
		i = 0;
		while (i < game->height)
			free(game->collected_flags[i++]);
		free(game->collected_flags);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}