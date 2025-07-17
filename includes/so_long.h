#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <X11/X.h>
#include "../libft/gnl/get_next_line.h"
#include "../libft/ft_printf/ft_printf.h"

#define TILE_SIZE 64
#define WIDTH 10 * TILE_SIZE
#define HEIGHT 8 * TILE_SIZE
#define MAX_MAP_WIDTH 100
#define MAX_MAP_HEIGHT 100


typedef struct s_game
{
	void	*mlx;
	void	*win;

	char 	**map;
	int		width;
	int		height;

	int 	player_x;
	int 	player_y;

	int		collected;
	int		total_collectibles;
	int		moves;

	int		**collected_flags;

	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_chest_open;
	void	*img_chest_closed;
	void	*img_exit_closed;
	void	*img_exit_open;

	int		player_facing;
	int		step_counter;

	void	*img_run_up_1;
	void	*img_run_up_2;
	void	*img_run_down_1;
	void	*img_run_down_2;
	void	*img_run_left_1;
	void	*img_run_left_2;
	void	*img_run_right_1;
	void	*img_run_right_2;

} t_game;

int	init_game(t_game *game);
void	free_map(char **map);
int	parse_map(char *file, t_game *game);
void	*ft_memset(void *b, int c, size_t len);

int close_window(t_game *game);
int handle_key(int keycode, t_game *game);

int	validate_map(char **map, t_game *game);
int	is_rectangular(char **map, int height, int width);
int	is_surrounded_by_walls(char **map, int height, int width);
int	validate_content(char **map, int height, t_game *game);


void	render_map(t_game *g);
int     load_images(t_game *r);


void	move_player(t_game *game, int dy, int dx);
void	check_collectible(t_game *game, int y, int x);
void	init_collected_flags(t_game *game);
void	free_resources(t_game *game);


#endif