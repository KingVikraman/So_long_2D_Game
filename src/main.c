#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		return (1);
	}

	// Step 1: Initialize game struct to 0
	ft_memset(&game, 0, sizeof(t_game));

	// Step 2: Parse map from file
	if (!parse_map(argv[1], &game))
	{
		write(2, "Error: Failed to parse map\n", 28);
		return (1);
	}

	//Step 3: Validate the map
	if (!validate_map(game.map, &game))
	{
		free_map(game.map);
		return (1);
	}

	// 💡 If everything passes, you can proceed to MLX rendering later
	write(1, "Map is valid!\n", 14);

	if (!init_game(&game))
		return (write(2, "Error: MLX failed\n", 18), 1);

	mlx_loop(game.mlx);


	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
