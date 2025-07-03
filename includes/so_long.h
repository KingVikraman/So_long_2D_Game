#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
// #include <mlx.h>

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


#endif