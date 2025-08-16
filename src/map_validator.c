#include "../includes/so_long.h"

int	validate_map(char **map, t_game *game);
int is_map_valid_with_floodfill(t_game *game);
int	is_rectangular(char **map, int height, int width);
int	validate_content(char **map, int height, t_game *game);
int	is_surrounded_by_walls(char **map, int height, int width);
static int	check_tile(char tile, int x, int y, t_game *game);



int	is_rectangular(char **map, int height, int width)
{
	int i;
	int row_len;

	i = 0;
	while (i < height)
	{
		row_len = 0;
		while (map[i][row_len] && map[i][row_len] != '\n')
			row_len++;
		if (row_len != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map, int height, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}


int	validate_content(char **map, int height, t_game *game)
{
	int	x;
	int	y;

	game->player_count = 0;
	game->exit_count = 0;
	game->total_collectibles = 0;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (map[y][++x] && map[y][x] != '\n')
			if (!check_tile(map[y][x], x, y, game))
				return (0);
	}
	if (game->player_count != 1 || game->exit_count < 1
		|| game->total_collectibles < 1)
		return (0);
	return (1);
}

static int	check_tile(char tile, int x, int y, t_game *game)
{
	if (tile == 'P')
	{
		game->player_count++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'E')
		game->exit_count++;
	else if (tile == 'C')
		game->total_collectibles++;
	else if (tile != '1' && tile != '0')
		return (0);
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	if (!is_rectangular(map, game->height, game->width))
	{
		ft_printf("Error\nMap is not rectangular\n");
		return(0);
	}
	if (!is_surrounded_by_walls(map, game->height, game->width))
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		return (0);
	}
	if (!validate_content(map, game->height, game))
	{
		ft_printf("Error\nInvalid characters or wrong counts\n");
		return (0);
	}
	if (!is_map_valid_with_floodfill(game))
	{
		ft_printf("Error\nUnreachable collectible or exit\n");
		return (0);
	}
	return (1);
}

// int is_map_valid_with_floodfill(t_game *game)
// {
// 	char	**temp_map;
// 	int		y;
// 	int 	x;
// 	int		valid;
// 	int count;

// 	valid = 1;
// 	count = game->total_collectibles;

// 	temp_map = duplicate_map(game->map, game->height);
// 	if (!temp_map)
// 		return (0);

// 	flood_fill(temp_map, game->player_y, game->player_x, &count);

// 	y = 0;
// 	while (y < game->height)
// 	{
// 		x = 0;
// 		while (x < game->width)
// 		{
// 			if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E')
// 				valid = 0;
// 			x++;
// 		}
// 		y++;
// 	}
// 	y = 0;
// 	while (y < game->height)
// 		free(temp_map[y++]);
// 	free(temp_map);

// 	return (valid);
// }

static int	has_unreachable_items(char **map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	free_temp_map(char **map, int height)
{
	int	y;

	y = 0;
	while (y < height)
		free(map[y++]);
	free(map);
}

int	is_map_valid_with_floodfill(t_game *game)
{
	char	**temp_map;
	int		count;

	count = game->total_collectibles;
	temp_map = duplicate_map(game->map, game->height);
	if (!temp_map)
		return (0);
	flood_fill(temp_map, game->player_y, game->player_x, &count);
	if (has_unreachable_items(temp_map, game->height, game->width))
	{
		free_temp_map(temp_map, game->height);
		return (0);
	}
	free_temp_map(temp_map, game->height);
	return (1);
}
