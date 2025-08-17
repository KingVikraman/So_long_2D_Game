#include "../includes/so_long.h"

char	**duplicate_map(char **original, int height);
void	flood_fill(char **map, int y, int x, int *collect_count);

char	**duplicate_map(char **original, int height)
{
	int		i;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = strdup(original[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **map, int y, int x, int *collect_count)
{
	if (map[y][x] == '1' || map[y][x] == 'F' ||
		(map[y][x] == 'E' && *collect_count > 0))
		return ;
	if (map[y][x] == 'C')
		(*collect_count)--;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, collect_count);
	flood_fill(map, y - 1, x, collect_count);
	flood_fill(map, y, x + 1, collect_count);
	flood_fill(map, y, x - 1, collect_count);
}

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
