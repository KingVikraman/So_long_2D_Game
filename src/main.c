#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;
	int			i;

	if (argc != 2)
	{
		//write(2, "Usage: ./so_long map.ber\n", 26);
		ft_printf("Error\n");
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}

	// Step 1: Initialize game struct to 0
	ft_memset(&game, 0, sizeof(t_game));

	// Step 2: Parse map from file
	if (!parse_map(argv[1], &game))
	{
		//write(2, "Error: Failed to parse map\n", 28);
		ft_printf("Error\n");
		ft_printf("Failed to parse map\n");
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
		ft_printf("Error\n");
		ft_printf("Memory allocation failure\n");
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
			//free_map(game.map);
			ft_printf("Error\n");
			ft_printf("Memory allocation failure\n");
			return(1);
		}
		i++;
	}

	init_collected_flags(&game);

	// 💡 If everything passes, you can proceed to MLX rendering later
	ft_printf("Map parsed and validated successfully\n");

	if (!init_game(&game))
	{
		free_resources(&game);
		ft_printf("Error\n");
		ft_printf("MLX failed\n");
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
	mlx_loop_hook(game.mlx, idle_check_loop, &game);
	mlx_loop(game.mlx);


	return (0);
}


