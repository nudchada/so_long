/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:47:36 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/16 16:48:55 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
	{
		ft_printf("Move: %d\nYou win!\n", ++game->move);
		exit_game(game);
	}
	else if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		game->map[y][x] = '0';
		put_images(game, y, x);
		if (game->map[new_y][new_x] == 'C')
			game->collectible--;
		game->player_y = new_y;
		game->player_x = new_x;
		game->map[new_y][new_x] = 'P';
		game->moves++;
		ft_printf("Move: %d\n", game->move);
		put_images(game, new_y, new_x);
	}
}

void	handle_key(int keysym, t_game *game)
{
	if (keysym == ESC)
		exit_game(game);
	else if (keysym == UP || keysym == W)
		move_player(game, game->player_y - 1, game->player_x);
	else if (keysym == DOWN || keysym == S)
		move_player(game, game->player_y + 1, game->player_x);
	else if (keysym == LEFT || keysym == A)
		move_player(game, game->player_y, game->player_x - 1);
	else if (keysym == RIGHT || keysym == D)
		move_player(game, game->player_y, game->player_x + 1);
}
