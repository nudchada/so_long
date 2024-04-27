/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:07:20 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/22 11:57:37 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_png(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		handle_errors(game, "Memory allocation failure.\n");
	game->texture->floor = mlx_load_png("textures/floor.png");
	game->texture->wall = mlx_load_png("textures/wall.png");
	game->texture->exit = mlx_load_png("textures/exit.png");
	game->texture->collectible = mlx_load_png("textures/collectible.png");
	game->texture->player = mlx_load_png("textures/player.png");
	if (!game->texture->floor || !game->texture->wall || !game->texture->exit
		|| !game->texture->collectible || !game->texture->player)
		handle_errors(game, "Unable to open image file.\n");
}

void	texture_to_image(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if (!game->image)
		handle_errors(game, "Memory allocation failure.\n");
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->collectible = mlx_texture_to_image(game->mlx, \
		game->texture->collectible);
	game->image->player = mlx_texture_to_image(game->mlx, \
		game->texture->player);
	if (!game->image->floor || !game->image->wall || !game->image->exit
		|| !game->image->collectible || !game->image->player)
		handle_errors(game, "Unable to open texture file.\n");
}

static void	put_floor(t_game *game, int y, int x)
{
	if (mlx_image_to_window(game->mlx, game->image->floor, \
		IMG_SIZE * x, IMG_SIZE * y) < 0)
		handle_errors(game, "Unable to put image to window.\n");
}

void	put_player(t_game *game, int y, int x)
{
	if (mlx_image_to_window(game->mlx, \
		game->image->player, IMG_SIZE * x, IMG_SIZE * y) < 0)
		handle_errors(game, "Unable to put image to window.\n");
}

void	put_images(t_game *game, int y, int x)
{
	put_floor(game, y, x);
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, \
			game->image->wall, IMG_SIZE * x, IMG_SIZE * y) < 0)
			handle_errors(game, "Unable to put image to window.\n");
	}
	else if (game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, \
			game->image->exit, IMG_SIZE * x, IMG_SIZE * y) < 0)
			handle_errors(game, "Unable to put image to window.\n");
	}
	else if (game->map[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, \
			game->image->collectible, IMG_SIZE * x, IMG_SIZE * y) < 0)
			handle_errors(game, "Unable to put image to window.\n");
	}
	else if (game->map[y][x] == 'P')
	{
		put_player(game, y, x);
	}
}
