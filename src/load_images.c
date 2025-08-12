
#include "../includes/so_long.h"

// int	load_images(t_game *r)
// {
// 	int	w;
// 	int	h;

// 	r->img_wall = mlx_xpm_file_to_image(r->mlx, "assets/wall.xpm", &w, &h);
// 	r->img_floor = mlx_xpm_file_to_image(r->mlx, "assets/floor.xpm", &w, &h);
// 	r->img_chest_closed = mlx_xpm_file_to_image(r->mlx, "assets/Collectible/closed_chest.xpm", &w, &h);
// 	r->img_chest_open = mlx_xpm_file_to_image(r->mlx, "assets/Collectible/open_chest.xpm", &w, &h);
// 	r->img_exit_closed = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_close.xpm", &w, &h);
// 	r->img_exit_open = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_open.xpm", &w, &h);
// 	r->img_idle = mlx_xpm_file_to_image(r->mlx, "assets/idle_player.xpm", &w, &h);


// 	//  Player animations

// 	r->img_run_up_1      = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_up_1.xpm", &w, &h);
// 	r->img_run_up_2      = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_up_2.xpm", &w, &h);
// 	r->img_run_down_1    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_1.xpm", &w, &h);
// 	r->img_run_down_2    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_2.xpm", &w, &h);
// 	r->img_run_left_1    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_left_1.xpm", &w, &h);
// 	r->img_run_left_2    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_left_2.xpm", &w, &h);
// 	r->img_run_right_1   = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_right_1.xpm", &w, &h);
// 	r->img_run_right_2   = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_right_2.xpm", &w, &h);

// 	if (!r->img_wall || !r->img_floor || !r->img_chest_closed || !r->img_chest_open ||
// 		!r->img_exit_closed || !r->img_exit_open ||
// 		!r->img_run_up_1 || !r->img_run_up_2 ||
// 		!r->img_run_down_1 || !r->img_run_down_2 ||
// 		!r->img_run_left_1 || !r->img_run_left_2 ||
// 		!r->img_run_right_1 || !r->img_run_right_2 || !r->img_idle)
// 	{
// 		ft_printf("Error\n");
// 		ft_printf("Failed to load one or more sprites\n");
// 		free_resources(r);
// 		return (0);
// 	}
// 	return (1);
// }


static	void load_environment_images(t_game *game, int *w, int *h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", w, h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", w, h);
	game->img_exit_closed = mlx_xpm_file_to_image(game->mlx, "assets/exit_door_close.xpm", w, h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, "assets/exit_door_open.xpm", w, h);
}


static	void load_collectible_images(t_game *game, int *w, int *h)
{
	game->img_chest_closed = mlx_xpm_file_to_image(game->mlx, "assets/Collectible/closed_chest.xpm", w, h);
	game->img_chest_open = mlx_xpm_file_to_image(game->mlx, "assets/Collectible/open_chest.xpm", w, h);
}

static void	load_player_images(t_game *game, int *w, int *h)
{
	game->img_idle = mlx_xpm_file_to_image(game->mlx, "assets/idle_player.xpm", w, h);
	game->img_run_up_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_up_1.xpm", w, h);
	game->img_run_up_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_up_2.xpm", w, h);
	game->img_run_down_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_down_1.xpm", w, h);
	game->img_run_down_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_down_2.xpm", w, h);
	game->img_run_left_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_left_1.xpm", w, h);
	game->img_run_left_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_left_2.xpm", w, h);
	game->img_run_right_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_right_1.xpm", w, h);
	game->img_run_right_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player/run_right_2.xpm", w, h);
}

static int	validate_images(t_game *game)
{
	if (!game->img_wall || !game->img_floor
		|| !game->img_chest_closed || !game->img_chest_open
		|| !game->img_exit_closed || !game->img_exit_open
		|| !game->img_idle
		|| !game->img_run_up_1 || !game->img_run_up_2
		|| !game->img_run_down_1 || !game->img_run_down_2
		|| !game->img_run_left_1 || !game->img_run_left_2
		|| !game->img_run_right_1 || !game->img_run_right_2)
	{
		ft_printf("Error\n");
		ft_printf("Failed to load one or more sprites\n");
		return (0);
	}
	return (1);
}

int	load_images(t_game *game)
{
	int	w;
	int	h;

	load_environment_images(game, &w, &h);
	load_collectible_images(game, &w, &h);
	load_player_images(game, &w, &h);
	if (!validate_images(game))
	{
		free_resources(game);
		return (0);
	}
	return (1);
}
