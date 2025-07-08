#include "../includes/so_long.h"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static int	get_width(char *line)
{
	int	i = 0;

	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	parse_map(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	game->height = count_lines(file);
	if (game->height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		game->map[i++] = line;
		if (i == 1)
			game->width = get_width(line);
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
