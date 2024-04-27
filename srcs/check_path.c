/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:13:19 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/19 10:39:51 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_game *game)
{
	char	**temp_map;
	int		i;

	temp_map = ft_calloc(game->rows + 1, sizeof(char *));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < game->rows)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		if (!temp_map[i])
		{
			free_array(temp_map);
			return (NULL);
		}
		i++;
	}
	return (temp_map);
}

static void	flood_fill(t_game *game, char **temp_map, int y, int x)
{
	if (x < 0 || x >= game->cols || y < 0 || y >= game->rows
		|| temp_map[y][x] == '1' || temp_map[y][x] == 'x'
		|| temp_map[y][x] == 'E')
		return ;
	temp_map[y][x] = 'x';
	flood_fill(game, temp_map, y + 1, x);
	flood_fill(game, temp_map, y - 1, x);
	flood_fill(game, temp_map, y, x + 1);
	flood_fill(game, temp_map, y, x - 1);
}

static bool	check_valid_path(char **temp_map, int y, int x)
{
	if (temp_map[y][x] == 'C' || (temp_map[y][x] == 'E' \
		&& (temp_map[y - 1][x] != 'x' && temp_map[y + 1][x] != 'x' \
		&& temp_map[y][x - 1] != 'x' && temp_map[y][x + 1] != 'x')))
		return (false);
	return (true);
}

void	check_path(t_game *game)
{
	char	**temp_map;
	int		x;
	int		y;

	temp_map = copy_map(game);
	if (!temp_map)
		handle_errors(game, "Memory allocation failure\n");
	flood_fill(game, temp_map, game->player_y, game->player_x);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!check_valid_path(temp_map, y, x))
			{
				free_array(temp_map);
				handle_errors(game, "No valid path in the map\n");
			}
			x++;
		}
		y++;
	}
	free_array(temp_map);
}
