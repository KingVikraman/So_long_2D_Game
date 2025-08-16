#include "../includes/so_long.h"

int		idle_check_loop(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dy, int dx);

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

static char	get_direction(int dy, int dx)
{
	if (dy == -1)
		return ('U');
	if (dy == 1)
		return ('D');
	if (dx == -1)
		return ('L');
	if (dx == 1)
		return ('R');
	return ('D');
}

static int	is_blocked(t_game *game, int ny, int nx)
{
	if (ny < 0 || ny >= game->height || nx < 0 || nx >= game->width)
		return (1);
	if (game->map[ny][nx] == '1')
		return (1);
	return (0);
}

static int	is_exit(t_game *game, int ny, int nx)
{
	if (game->map[ny][nx] != 'E')
		return (0);
	if (game->collected == game->total_collectibles)
	{
		ft_printf("You won! Game completed in %d moves.\n", game->moves + 1);
		close_window(game);
	}
	else
		ft_printf("Collect all items before exiting!\n");
	return (1);
}

void	move_player(t_game *game, int dy, int dx)
{
	int	ny;
	int	nx;

	ny = game->player_y + dy;
	nx = game->player_x + dx;
	if (is_blocked(game, ny, nx) || is_exit(game, ny, nx))
		return ;
	game->player_facing = get_direction(dy, dx);
	game->step_counter++;
	check_collectible(game, ny, nx);
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;
	ft_printf("Moves: %d, Collected: %d/%d\n",
		game->moves, game->collected, game->total_collectibles);
	render_map(game);
}
