/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:34:18 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/19 10:43:40 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_cols(t_game *game)
{
	int	cols;
	int	i;

	cols = (int)ft_strlen(game->map[0]);
	i = 1;
	while (i < game->rows)
	{
		if ((int)(ft_strlen(game->map[i])) != cols)
			handle_errors(game, "The map must be rectangular.\n");
		i++;
	}
	game->cols = cols;
}

static void	count_components(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		game->collectible++;
	else if (game->map[y][x] == 'E')
		game->exit++;
	else if (game->map[y][x] == 'P')
	{
		game->player++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (!(game->map[y][x] == '1' || game->map[y][x] == '0'))
		handle_errors(game, "The map be constructed with invalid component.\n");
}

static void	check_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (y == 0 || y == game->rows -1 || x == 0 || x == game->cols -1)
			{
				if (game->map[y][x] != '1')
					handle_errors(game, "Map must be surrounded by walls.\n");
			}
			else
				count_components(game, y, x);
			x++;
		}
		y++;
	}
}

void	check_valid_map(t_game *game)
{
	check_cols(game);
	check_components(game);
	if (game->collectible < 1)
		handle_errors(game, "The map must contain at least 1 collectible.\n");
	if (game->exit != 1)
		handle_errors(game, "The map must contain 1 exit.\n");
	if (game->player != 1)
		handle_errors(game, "The map must contain 1 player.\n");
	check_path(game);
}
