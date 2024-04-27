/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:22 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/22 18:04:25 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		handle_errors(&game, "Incorrect number of arguments.\n");
	init_map(&game, argv[1]);
	game.mlx = mlx_init(game.cols * IMG_SIZE, game.rows * IMG_SIZE, \
		"so_long", true);
	if (!game.mlx)
		handle_errors(&game, "Unable to initialize mlx.\n");
	render_map(&game);
	mlx_key_hook(game.mlx, &handle_key, &game);
	mlx_close_hook(game.mlx, exit_game, &game);
	mlx_loop(game.mlx);
}

// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init(400, 300, "test", true);
// 	mlx_terminate(mlx);
// }
