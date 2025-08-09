#include "../includes/so_long.h"

char **duplicate_map(char **original, int height)
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
			// Clean up on failure
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


void flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F') // wall or visited
		return;

	map[y][x] = 'F'; // Mark as visited

	flood_fill(map, y + 1, x); // down
	flood_fill(map, y - 1, x); // up
	flood_fill(map, y, x + 1); // right
	flood_fill(map, y, x - 1); // left
}
