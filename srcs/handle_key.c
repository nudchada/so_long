/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:47:36 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/19 12:19:48 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_on_exit(t_game *game, int new_y, int new_x)
{
	put_player(game, new_y, new_x);
	ft_printf("Move: %d\nYou win!\n", ++game->move);
	exit_game(game);
}

static void	move_player(t_game *game, int new_y, int new_x)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
	{
		game->map[y][x] = '0';
		put_images(game, y, x);
		player_on_exit(game, new_y, new_x);
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
		game->move++;
		ft_printf("Move: %d\n", game->move);
		put_images(game, new_y, new_x);
	}
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_game(game);
	else if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) \
		|| (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS))
		move_player(game, game->player_y - 1, game->player_x);
	else if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS) \
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS))
		move_player(game, game->player_y + 1, game->player_x);
	else if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) \
		|| (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS))
		move_player(game, game->player_y, game->player_x - 1);
	else if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) \
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
		move_player(game, game->player_y, game->player_x + 1);
}
