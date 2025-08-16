#include "../includes/so_long.h"

/* FUNCTION PROTOTYPING */

int     idle_check_loop(t_game *game);
int	    handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dy, int dx);
static	void	update_moves(t_game * game);
static	void	handle_movement(int keycode, t_game * game);


/* FUNCTIONS*/

// int	handle_key(int keycode, t_game *game)
// {

// 	struct timeval current_time;
// 	gettimeofday(&current_time, NULL);
// 	game->last_input_time = current_time;


//     if (keycode == 65307) // ESC key
//         close_window(game);

//     else if (keycode == 119 || keycode == 65362) // W or Up arrow
//     {
//         game->is_idle = 0;
// 		gettimeofday(&game->last_input_time, NULL);
//         move_player(game, -1, 0);
//     }

//     else if (keycode == 115 || keycode == 65364) // S or Down arrow
//     {
//         game->is_idle = 0;
// 		gettimeofday(&game->last_input_time, NULL);
//         move_player(game, 1, 0);
//     }

//     else if (keycode == 97 || keycode == 65361) // A or Left arrow
//     {
//         game->is_idle = 0;
// 		gettimeofday(&game->last_input_time, NULL);
//         move_player(game, 0, -1);
//     }
		
//     else if (keycode == 100 || keycode == 65363) // D or Right arrow
//     {
//         game->is_idle = 0;
//         gettimeofday(&game->last_input_time, NULL);
//         move_player(game, 0, 1);
//     }    
//     return (0);
// }


int	handle_key(int keycode, t_game *game)
{
	gettimeofday(&game->last_input_time, NULL);
	if (keycode == 65307) // ESC
		close_window(game);
	else
		handle_movement(keycode, game);
	return (0);
}

static	void	handle_movement(int keycode, t_game * game)
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

static	void	update_moves(t_game * game)
{
	game->is_idle = 0;
	gettimeofday(&game->last_input_time, NULL);
}

int     idle_check_loop(t_game *game)
{
    struct timeval  now;
    long            diff;

    gettimeofday(&now, NULL);
    diff = (now.tv_sec - game->last_input_time.tv_sec) * 1000 +
            (now.tv_usec - game->last_input_time.tv_usec) / 1000;

    if (diff > 1000 && !game->is_idle)
        game->is_idle = 1;

    render_map(game);
    return (0);
}

void	move_player(t_game *game, int dy, int dx)
{
	int ny = game->player_y + dy;
	int nx = game->player_x + dx;

	//  Bound check
	if (ny < 0 || ny >= game->height || nx < 0 || nx >= game->width)
		return;

	//  Wall check
	if (game->map[ny][nx] == '1')
		return;

	//  Exit check
	if (game->map[ny][nx] == 'E' && game->collected == game->total_collectibles)
	{
		ft_printf("You won! Game completed in %d moves.\n", game->moves + 1);
		close_window(game);
		return;
	}
	else if (game->map[ny][nx] == 'E')
	{
		ft_printf("Collect all items before exiting!\n");
		return;
	}

	//  Update player direction
	if (dy == -1)
		game->player_facing = 'U';
	else if (dy == 1)
		game->player_facing = 'D';
	else if (dx == -1)
		game->player_facing = 'L';
	else if (dx == 1)
		game->player_facing = 'R';

	//  Step counter for animation
	game->step_counter++;

	//  Collectible check
	check_collectible(game, ny, nx);

	//  Update player position
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;

	ft_printf("Moves: %d, Collected: %d/%d\n",
		game->moves, game->collected, game->total_collectibles);

	//  Redraw everything (calls draw_player() inside render_map)
	render_map(game);
}