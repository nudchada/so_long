/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:29:43 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/22 11:30:44 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	delete_texture(t_game *game)
{
	if (game->texture->floor)
		mlx_delete_texture(game->texture->floor);
	if (game->texture->wall)
		mlx_delete_texture(game->texture->wall);
	if (game->texture->exit)
		mlx_delete_texture(game->texture->exit);
	if (game->texture->collectible)
		mlx_delete_texture(game->texture->collectible);
	if (game->texture->player)
		mlx_delete_texture(game->texture->player);
}

static void	delete_image(t_game *game)
{
	if (game->image->floor)
		mlx_delete_image(game->mlx, game->image->floor);
	if (game->image->wall)
		mlx_delete_image(game->mlx, game->image->wall);
	if (game->image->exit)
		mlx_delete_image(game->mlx, game->image->exit);
	if (game->image->collectible)
		mlx_delete_image(game->mlx, game->image->collectible);
	if (game->image->player)
		mlx_delete_image(game->mlx, game->image->player);
}

void	clean_up(t_game *game)
{
	free_array(game->map);
	if (game->texture)
	{
		delete_texture(game);
		free(game->texture);
	}
	if (game->image)
	{
		delete_image(game);
		free(game->image);
	}
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
	}
}
