/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:15 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/15 22:20:27 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
//# include "../MLX42/include/MLX42/MLX42.h"
//# include "../MLX42/include/MLX42_Int.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdbool.h>

# define IMG_SIZE 64
# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*floor_img;
	void	*wall_img;
	void	*exit_img;
	void	*collectible_img;
	void	*player_img;
	char	**map;
	int		rows;
	int		cols;
	int		exit;
	int		collectible;
	int		player;
	int		player_x;
	int		player_y;
	int		moves;
}	t_game;

void	check_path(t_game *game);
void	check_valid_map(t_game *game);
void	init_map(t_game *game, char *map_file);
void	init_game(t_game *game);
void	put_images(t_game *game, int y, int x);
void	render_map(t_game *game);

void	handle_errors(t_game game, char *message);
void	exit_game(t_game *game);

#endif