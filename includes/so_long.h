#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "../libft/gnl/get_next_line.h"


typedef struct s_game
{
	char 	**map;
	int		width;
	int		height;
	int 	player_x;
	int 	player_y;
	int		collectibles;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;

} t_game;

int	init_game(t_game *game);
void	free_map(char **map);
int	parse_map(char *file, t_game *game);
void	*ft_memset(void *b, int c, size_t len);


int	validate_map(char **map, t_game *game);
int	is_rectangular(char **map, int height, int width);
int	is_surrounded_by_walls(char **map, int height, int width);
int	validate_content(char **map, int height, t_game *game);


#endif