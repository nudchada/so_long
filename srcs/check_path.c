/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:40:30 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/13 11:40:30 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_game game)
{
	char	**temp_map;
	int		i;

	temp_map = (char **)malloc((game->rows + 1) * sizeof(char *));
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

static void	flood_fill(t_game game, char **temp_map, int x, int y)
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

void	check_path(t_game *game)
{
	char	**temp_map;
	int 	x;
	int		y;

	y = 0;
	temp_map = copy_map(game);
	if (!temp_map)
		handle_errors(game, "Memory allocation failure\n");
	flood_fill(map, temp_map, game->player_x, game->player_y);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols){
			if (temp_map[y][x] == 'C' || (temp_map[y][x] == 'E' 
				&& (temp_map[y - 1][x] != 'x' && temp_map[y + 1][x] != 'x'
				&& temp_map[y][x - 1] != 'x' && temp_map[y][x + 1] != 'x')))
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
