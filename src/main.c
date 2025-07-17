#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;
	int			i;

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

	game.collected_flags = (int **)malloc(sizeof(int *) * game.height);
	if (!game.collected_flags)
	{
		free_map(game.map);
		printf("Error: Memory allocation failure\n"); 
		return (1);
	}

	i = 0;
	while (i < game.height)
	{
		game.collected_flags[i] = (int *)malloc(sizeof(int) * game.width);
		if (!game.collected_flags[i])
		{
			while (--i >= 0)
				free(game.collected_flags[i]);
			free(game.collected_flags);
			free_map(game.map);
			printf("Error: Memory allocation failure\n");
			return(1);
		}
		i++;
	}

	init_collected_flags(&game);

	// 💡 If everything passes, you can proceed to MLX rendering later
	printf("Map parsed and validated successfully\n");

	if (!init_game(&game))
	{
		free_resources(&game);
		printf("Error: MLX failed\n");
		return (1);
	}
	
	if (!load_images(&game))
	{
		free_resources(&game);	
		return (1);
	}


	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);


	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
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


int	handle_key(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        close_window(game);
    else if (keycode == 119 || keycode == 65362) // W or Up arrow
        move_player(game, -1, 0);
    else if (keycode == 115 || keycode == 65364) // S or Down arrow
        move_player(game, 1, 0);
    else if (keycode == 97 || keycode == 65361) // A or Left arrow
        move_player(game, 0, -1);
    else if (keycode == 100 || keycode == 65363) // D or Right arrow
        move_player(game, 0, 1);
    return (0);
}
