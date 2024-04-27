/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:59 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/22 11:31:34 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_errors(t_game *game, char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	clean_up(game);
	exit(1);
}

void	exit_game(void *param)
{
	t_game	*game;

	game = param;
	clean_up(game);
	exit(0);
}
