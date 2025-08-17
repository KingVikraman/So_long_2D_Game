#include "../includes/so_long.h"

static	int	validate_args(int argc, char *path)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long maps/map.ber\n");
		return (0);
	}
	len = ft_strlen(path);
	if (ft_strcmp(".ber", (path + (len - 4))) != 0)
		return (printf("Error\nUsage : Not a .ber file!\n"), 0);
	return (1);
}

static	int	init_game_structs(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!parse_map(map_path, game))
	{
		ft_printf("Error\nFailed to parse map\n");
		return (0);
	}
	if (!validate_map(game->map, game))
	{
		free_map(game->map);
		return (0);
	}
	return (1);
}

static	int	memory_allocation(t_game *game)
{
	int	i;

	game->collected_flags = malloc(sizeof(int *) * game->height);
	if (!game->collected_flags)
	{
		free_map(game->map);
		ft_printf("Error\nMemory allocation failure\n");
		return (0);
	}
	i = -1;
	while (++i < game->height)
	{
		game->collected_flags[i] = malloc(sizeof(int) * game->width);
		if (!game->collected_flags[i])
		{
			while (--i >= 0)
				free(game->collected_flags[i]);
			free(game->collected_flags);
			ft_printf("Error\nMemory allocation failure\n");
			return (0);
		}
	}
	init_collected_flags(game);
	return (1);
}

static	int	game_lauch(t_game *game)
{
	if (!init_game(game))
	{
		free_resources(game);
		ft_printf("Error\nMLX failed\n");
		return (0);
	}
	if (!load_images(game))
	{
		free_resources(game);
		return (0);
	}
	render_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_loop_hook(game->mlx, idle_check_loop, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!validate_args(argc, argv[1]))
		return (1);
	if (!init_game_structs(&game, argv[1]))
		return (1);
	if (!memory_allocation(&game))
		return (1);
	ft_printf("Map parsed and validated successfully\n");
	if (!game_lauch(&game))
		return (1);
	return (0);
}
