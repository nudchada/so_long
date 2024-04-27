/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:15 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/22 11:31:59 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>

# define IMG_SIZE 64

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			rows;
	int			cols;
	int			exit;
	int			collectible;
	int			player;
	int			player_x;
	int			player_y;
	int			move;
	t_texture	*texture;
	t_image		*image;
}	t_game;

void	check_path(t_game *game);
void	check_valid_map(t_game *game);
void	init_map(t_game *game, char *map_file);
void	load_png(t_game *game);
void	texture_to_image(t_game *game);
void	put_player(t_game *game, int y, int x);
void	put_images(t_game *game, int y, int x);
void	render_map(t_game *game);
void	handle_key(mlx_key_data_t keydata, void *param);
void	free_array(char **array);
void	clean_up(t_game *game);
void	handle_errors(t_game *game, char *message);
void	exit_game(void *param);

#endif