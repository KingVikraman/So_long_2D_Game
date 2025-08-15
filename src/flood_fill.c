#include "../includes/so_long.h"

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
