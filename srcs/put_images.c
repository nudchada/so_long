/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:59:10 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/15 14:59:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	xpm_to_img(t_game *game)
{
	int	size;

	size = IMG_SIZE;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "../imgs/floor.xpm", &size, &size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "../imgs/wall.xpm", &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "../imgs/exit.xpm", &size, &size);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
		"../imgs/collectible.xpm", &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "../imgs/player.xpm", &size, &size);
	if (!game->floor_img || !game->wall_img || !game->exit_img
		|| !game->collectible_img || !game->player_img)
		handle_errors(game, "Unable to open image file.\n");
}

void	put_images(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->floor_img, IMG_SIZE * x, IMG_SIZE * y);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img, IMG_SIZE * x, IMG_SIZE * y);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_img, IMG_SIZE * x, IMG_SIZE * y);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectible_img, IMG_SIZE * x, IMG_SIZE * y);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_img, IMG_SIZE * x, IMG_SIZE * y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	xpm_to_img(game);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			put_images(game, y, x);
			x++;
		}
		y++;
	}
}
