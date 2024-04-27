# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 11:48:10 by nusamank          #+#    #+#              #
#    Updated: 2024/04/22 17:16:37 by nusamank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
MLX_PATH = MLX42
# MLXFLAGS    := -L ${MLX_PATH} -lmlx42 -lglfw -lm
MLX_A = $(MLX_PATH)/build/libmlx42.a

LIBFT = libft/libft.a
HEAD = includes
SRCDIR = srcs
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_A)
	$(CC) $(CFLAGS) -I $(HEAD) $(OBJS) $(LIBFT) $(MLX_A) $(MLXFLAGS) -o $@

$(LIBFT):
	make -C libft
	
$(MLX_A): | $(MLX_PATH)
	cmake $(MLX_PATH) -B $(MLX_PATH)/build
	make -C $(MLX_PATH)/build -j4

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR) $(HEAD)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)
	
clean:
	rm -rf $(BINDIR)
	make -C libft clean
	rm -rf $(MLX_PATH)/build

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re