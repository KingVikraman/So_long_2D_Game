#include "../includes/so_long.h"

void	free_map(char **map);
void	draw_player(t_game *game);
int		idle_check_loop(t_game *game);

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

int	idle_check_loop(t_game *game)
{
	struct timeval	now;
	long			diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec - game->last_input_time.tv_sec) * 1000
		+ (now.tv_usec - game->last_input_time.tv_usec) / 1000;
	if (diff > 1000 && !game->is_idle)
		game->is_idle = 1;
	render_map(game);
	return (0);
}
