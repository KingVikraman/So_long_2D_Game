
#include "../includes/so_long.h"

int	load_images(t_game *r)
{
	int	w;
	int	h;

	r->img_wall = mlx_xpm_file_to_image(r->mlx, "assets/wall.xpm", &w, &h);
	r->img_floor = mlx_xpm_file_to_image(r->mlx, "assets/floor.xpm", &w, &h);
	r->img_chest_closed = mlx_xpm_file_to_image(r->mlx, "assets/Collectible/closed_chest.xpm", &w, &h);
	r->img_chest_open = mlx_xpm_file_to_image(r->mlx, "assets/Collectible/open_chest.xpm", &w, &h);
	r->img_exit_closed = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_close.xpm", &w, &h);
	r->img_exit_open = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_open.xpm", &w, &h);
	r->img_idle = mlx_xpm_file_to_image(r->mlx, "assets/idle_player.xpm", &w, &h);


	//  Player animations

	r->img_run_up_1      = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_up_1.xpm", &w, &h);
	r->img_run_up_2      = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_up_2.xpm", &w, &h);
	r->img_run_down_1    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_1.xpm", &w, &h);
	r->img_run_down_2    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_2.xpm", &w, &h);
	r->img_run_left_1    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_left_1.xpm", &w, &h);
	r->img_run_left_2    = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_left_2.xpm", &w, &h);
	r->img_run_right_1   = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_right_1.xpm", &w, &h);
	r->img_run_right_2   = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_right_2.xpm", &w, &h);

	if (!r->img_wall || !r->img_floor || !r->img_chest_closed || !r->img_chest_open ||
		!r->img_exit_closed || !r->img_exit_open ||
		!r->img_run_up_1 || !r->img_run_up_2 ||
		!r->img_run_down_1 || !r->img_run_down_2 ||
		!r->img_run_left_1 || !r->img_run_left_2 ||
		!r->img_run_right_1 || !r->img_run_right_2 || !r->img_idle)
	{
		ft_printf("Error\n");
		ft_printf("Failed to load one or more sprites\n");
		free_resources(r);
		return (0);
	}
	return (1);
}



// void	draw_player(t_game *g)
// {
// 	void	*sprite;

// 	//  If player is idle, show the idle sprite based on direction
// 	if (g->is_idle)
// 	{
// 		sprite = g->img_idle;
// 	}
// 	else
// 	{
// 		//  Running animation
// 		if (g->player_facing == 'U')
// 			sprite = (g->step_counter % 2 == 0) ? g->img_run_up_1 : g->img_run_up_2;
// 		else if (g->player_facing == 'D')
// 			sprite = (g->step_counter % 2 == 0) ? g->img_run_down_1 : g->img_run_down_2;
// 		else if (g->player_facing == 'L')
// 			sprite = (g->step_counter % 2 == 0) ? g->img_run_left_1 : g->img_run_left_2;
// 		else
// 			sprite = (g->step_counter % 2 == 0) ? g->img_run_right_1 : g->img_run_right_2;
// 	}

// 	//  Render player sprite
// 	mlx_put_image_to_window(g->mlx, g->win, sprite,
// 		g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
// }


