#include "../includes/so_long.h"

int	validate_map(char **map, t_game *game);
int is_map_valid_with_floodfill(t_game *game);
int	is_rectangular(char **map, int height, int width);
int	validate_content(char **map, int height, t_game *game);
int	is_surrounded_by_walls(char **map, int height, int width);



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
	int x;
	int y;
	int player;
	int exit;
	int collect;

	player = 0;
	exit = 0;
	collect = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				player++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (map[y][x] == 'E')
				exit++;
			else if (map[y][x] == 'C')
				collect++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	if (player != 1 || exit < 1 || collect < 1)
		return (0);
	game->total_collectibles = collect;
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	if (!is_rectangular(map, game->height, game->width))
		return (write(2, "Error: Map is not rectangular\n", 31), 0);
	if (!is_surrounded_by_walls(map, game->height, game->width))
		return (write(2, "Error: Map is not surrounded by walls\n", 39), 0);
	if (!validate_content(map, game->height, game))
		return (write(2, "Error: Invalid characters or wrong counts\n", 42), 0);
	if (!is_map_valid_with_floodfill(game))
	{
		write(2, "Error: Unreachable collectible or exit\n", 39);
		return (0);
	}
	return (1);
}

int is_map_valid_with_floodfill(t_game *game)
{
	char	**temp_map;
	int		y, x;
	int		valid = 1;

	temp_map = duplicate_map(game->map, game->height);
	if (!temp_map)
		return (0);

	flood_fill(temp_map, game->player_y, game->player_x);

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E')
				valid = 0;
			x++;
		}
		y++;
	}
	// Free duplicated map
	y = 0;
	while (y < game->height)
		free(temp_map[y++]);
	free(temp_map);

	return (valid);
}
