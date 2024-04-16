/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:22 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/16 16:58:11 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_var(t_game game)
{
	game->rols = 0;
	game->cols = 0;
	game->exit = 0;
	game->collectible = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_errors(game, "Unable to initialize mlx.\n");
	game->window = mlx_new_window(game->mlx, 800, 600, "so_long");
	if (!game->window)
		handle_errors(game, "Unable to open window.\n");
	//mlx_pixel_put(game->mlx, game->window, 100, 100, 0xFF0000);
	
}

int	main(int argc, char **argv)
{
	t_game	*game;

	//game = NULL;
	if (argc != 2)
		return (1);
	init_var(game);
	init_map(game, argv[1]);	
	init_game(game);
	render_map(game);
	mlx_key_hook(game->window, handle_key, game);
	mlx_hook(game->window, 17, 1L>>17, exit_game, game);
	// img = mlx_xpm_file_to_image(mlx, "../imgs/Grass-1.xpm", &tile_size, &tile_size);
	// mlx_put_image_to_window(mlx, win, img, 100, 100);
	//mlx_pixel_put(game->mlx, game->win, 100, 100, 0xFF0000);
	mlx_loop(game->mlx);
//	free(mlx);
}
