#include "../includes/so_long.h"


int	handle_key(int keycode, t_game *game)
{

	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	game->last_input_time = current_time;


    if (keycode == 65307) // ESC key
        close_window(game);

    else if (keycode == 119 || keycode == 65362) // W or Up arrow
    {
        game->is_idle = 0;
		gettimeofday(&game->last_input_time, NULL);
        move_player(game, -1, 0);
    }

    else if (keycode == 115 || keycode == 65364) // S or Down arrow
    {
        game->is_idle = 0;
		gettimeofday(&game->last_input_time, NULL);
        move_player(game, 1, 0);
    }

    else if (keycode == 97 || keycode == 65361) // A or Left arrow
    {
        game->is_idle = 0;
		gettimeofday(&game->last_input_time, NULL);
        move_player(game, 0, -1);
    }
		
    else if (keycode == 100 || keycode == 65363) // D or Right arrow
    {
        game->is_idle = 0;
        gettimeofday(&game->last_input_time, NULL);
        move_player(game, 0, 1);
    }    
    return (0);
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