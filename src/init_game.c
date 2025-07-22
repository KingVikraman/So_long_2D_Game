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
	int i;
	int j;

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

void	move_player(t_game *game, int dy, int dx)
{
	int ny = game->player_y + dy;
	int nx = game->player_x + dx;

	// 1️⃣ Bound check
	if (ny < 0 || ny >= game->height || nx < 0 || nx >= game->width)
		return;

	// 2️⃣ Wall check
	if (game->map[ny][nx] == '1')
		return;

	// 3️⃣ Exit check
	if (game->map[ny][nx] == 'E' && game->collected == game->total_collectibles)
	{
		printf("You won! Game completed in %d moves.\n", game->moves + 1);
		close_window(game);
		return;
	}
	else if (game->map[ny][nx] == 'E')
	{
		printf("Collect all items before exiting!\n");
		return;
	}

	// 4️⃣ Update player direction
	if (dy == -1)
		game->player_facing = 'U';
	else if (dy == 1)
		game->player_facing = 'D';
	else if (dx == -1)
		game->player_facing = 'L';
	else if (dx == 1)
		game->player_facing = 'R';

	// 5️⃣ Step counter for animation
	game->step_counter++;

	// 6️⃣ Collectible check
	check_collectible(game, ny, nx);

	// 7️⃣ Update player position
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;

	printf("Moves: %d, Collected: %d/%d\n",
		game->moves, game->collected, game->total_collectibles);

	// 8️⃣ Redraw everything (calls draw_player() inside render_map)
	render_map(game);
}

int close_window(t_game *game)
{
	free_resources(game);
	//mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
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