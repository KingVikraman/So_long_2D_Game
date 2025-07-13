// #include "../includes/so_long.h"

// int     load_images(t_game *r)
// {
// 	int w;
// 	int h;

// 	r->img_wall		= mlx_xpm_file_to_image(r->mlx,"assets/wall.xpm", &w, &h);
// 	r->img_floor	= mlx_xpm_file_to_image(r->mlx,"assets/floor.xpm", &w,&h);
// 	// r->img_player	= mlx_xpm_file_to_image()
// 	// r->img_exit		= mlx_xpm_file_to_image()
// 	if (!r->img_wall)
// 		printf(" Error loading wall image\n");
// 	else if (!r->img_floor)
// 		printf(" Error loading floor image\n");

// 	else 
// 	{
// 		printf("Images loaded successfully\n");
// 		return (0);
// 	}
// 	return (1);
// }

// static void *choose_sprite(t_game *g , char c)
// {
// 	if (c == '1')
// 		return (g->img_wall);
// 	if (c == '0')
// 		return (g->img_floor);
// 	//if (c == "")
// 	return (NULL);
// }

// void	render_map(t_game *g)
// {
// 	int y;
// 	int x;

// 	mlx_clear_window(g->mlx, g->win);
// 	y = 0;
// 	while (y < g->height)
// 	{
// 		x = 0;
// 		while (x < g->width)
// 		{
// 			void *img = choose_sprite(g, g->map[y][x]);
// 			if (img)
// 				mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(g->mlx, g->win, g->img_player, g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
// }


// #include "../includes/so_long.h"

// int     load_images(t_game *r)
// {
//     int w;
//     int h;

//     r->img_wall = mlx_xpm_file_to_image(r->mlx, "assets/wall.xpm", &w, &h);
//     r->img_floor = mlx_xpm_file_to_image(r->mlx, "assets/floor.xpm", &w, &h);
//     r->img_collect = mlx_xpm_file_to_image(r->mlx, "assets/collectible.xpm", &w, &h);
//     r->img_exit = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_close.xpm", &w, &h);
//     r->img_player = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_1.xpm", &w, &h);

//     if (!r->img_wall)
//     {
//         printf("Error loading wall image\n");
//         return (0);
//     }
//     if (!r->img_floor)
//     {
//         printf("Error loading floor image\n");
//         return (0);
//     }
//     if (!r->img_collect)
//     {
//         printf("Error loading collectible image\n");
//         return (0);
//     }
//     if (!r->img_exit)
//     {
//         printf("Error loading exit image\n");
//         return (0);
//     }
//     if (!r->img_player)
//     {
//         printf("Error loading player image\n");
//         return (0);
//     }

//     printf("Images loaded successfully\n");
//     return (1);
// }

// static void *choose_sprite(t_game *g, char c)
// {
//     if (c == '1')
//         return (g->img_wall);
//     if (c == '0')
//         return (g->img_floor);
//     if (c == 'C')
//         return (g->img_collect);
//     if (c == 'E')
//         return (g->img_exit);
//     if (c == 'P')
//         return (g->img_floor);  // Show floor under player
//     return (NULL);
// }

// void	render_map(t_game *g)
// {
//     int y;
//     int x;

//     mlx_clear_window(g->mlx, g->win);
//     y = 0;
//     while (y < g->height)
//     {
//         x = 0;
//         while (x < g->width)
//         {
//             void *img = choose_sprite(g, g->map[y][x]);
//             if (img)
//                 mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
            
//             // If this is the player position, draw the player on top
//             if (g->map[y][x] == 'P')
//             {
//                 g->player_x = x;
//                 g->player_y = y;
//                 mlx_put_image_to_window(g->mlx, g->win, g->img_player, x * TILE_SIZE, y * TILE_SIZE);
//             }
//             x++;
//         }
//         y++;
//     }
// }

#include "../includes/so_long.h"

int     load_images(t_game *r)
{
    int w;
    int h;

    r->img_wall = mlx_xpm_file_to_image(r->mlx, "assets/wall.xpm", &w, &h);
    r->img_floor = mlx_xpm_file_to_image(r->mlx, "assets/floor.xpm", &w, &h);
    // r->img_collect = mlx_xpm_file_to_image(r->mlx, "assets/collectible.xpm", &w, &h);
    // r->img_exit = mlx_xpm_file_to_image(r->mlx, "assets/exit_door_close.xpm", &w, &h);
    // r->img_player = mlx_xpm_file_to_image(r->mlx, "assets/Player/run_down_1.xpm", &w, &h);

    if (!r->img_wall)
    {
        printf("Error loading wall image\n");
        return (0);
    }
    if (!r->img_floor)
    {
        printf("Error loading floor image\n");
        return (0);
    }

    printf("Images loaded successfully\n");
    return (1);
}

static void *choose_sprite(t_game *g, char c)
{
    if (c == '1')
        return (g->img_wall);
    if (c == '0')
        return (g->img_floor);
    if (c == 'C')
        return (g->img_floor);  // Show floor for collectible for now
    if (c == 'E')
        return (g->img_floor);  // Show floor for exit for now
    if (c == 'P')
        return (g->img_floor);  // Show floor under player
    return (NULL);
}

void	render_map(t_game *g)
{
    int y;
    int x;

    mlx_clear_window(g->mlx, g->win);
    y = 0;
    while (y < g->height)
    {
        x = 0;
        while (x < g->width)
        {
            void *img = choose_sprite(g, g->map[y][x]);
            if (img)
                mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
            
            // Find and store player position
            if (g->map[y][x] == 'P')
            {
                g->player_x = x;
                g->player_y = y;
                // For now, just show floor where player is
                // You can add player sprite later
            }
            x++;
        }
        y++;
    }
}