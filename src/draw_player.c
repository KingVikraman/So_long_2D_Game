#include "../includes/so_long.h"

static	void	*get_idle_sprite(t_game *game)
{
	return (game->img_idle);
}

static	void	*get_walking_sprite(t_game *game)
{
	if (game->player_facing == 'U')
	{
		if (game->step_counter % 2 == 0)
			return (game->img_run_up_1);
		else
			return (game->img_run_up_2);
	}
	else if (game->player_facing == 'D')
	{
		if (game->step_counter % 2 == 0)
			return (game->img_run_down_1);
		else
			return (game->img_run_down_2);
	}
	else if (game->player_facing == 'L')
	{
		if (game->step_counter % 2 == 0)
			return (game->img_run_left_1);
		else
			return (game->img_run_left_2);
	}
	if (game->step_counter % 2 == 0)
		return (game->img_run_right_1);
	return (game->img_run_right_2);
}

void	draw_player(t_game *game)
{
	void	*sprite;

	if (game->is_idle)
		sprite = get_idle_sprite(game);
	else
		sprite = get_walking_sprite(game);
	mlx_put_image_to_window(game->mlx, game->win, sprite, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
}
