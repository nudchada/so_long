/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:22 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/16 16:40:39 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_rows(t_game *game, char *map_file)
{
	int		map_fd;
	char	*map_line;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		handle_errors(game, "Unable to open map file.\n");
	while (1)
	{
		map_line = get_next_line(map_fd);
		if (!map_line)
			break ;
		game->rows++;
		free(map_line);
	}
	close(map_fd)
	if (!game->rows)
		handle_errors(game, "Unable to read map file.\n");
}

static void	add_map_line(t_game *game, char *line)
{
	int		i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		handle_errors(game, "Unable to open map file.\n");
	i = 0;
	while (i < game->rows)
	{
		map_line = get_next_line(map_fd);
		if (!map_line)
			break ;
		game->map[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
	}
	game->map[i] = NULL;
	close(map_fd);
}

void	init_map(t_game *game, char *map_file)
{
	if (!ft_strncmp(map_file[ft_strlen(map_file) - 4], ".ber", 4))
		handle_errors(game, "Map file does not end with .ber extension.\n");
	count_rows(game, map_file);
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		handle_errors(game, "Memory allocation failure.\n");
	add_map_line(game, map_file);
	if (!game->map)
		handle_errors(game, "Unable to read map file.\n");
	check_valid_map(game);
}

/**/
void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i])
		i++;
	}
}
