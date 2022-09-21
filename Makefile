# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouay <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:33:43 by adouay            #+#    #+#              #
#    Updated: 2022/09/21 12:38:34 by adouay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -Wall -Werror -Wextra

SRC = main.c \
		map.c \
		map2.c \
		path.c \
		render.c \
		move.c \
		free.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(OBJ) -g -L libft/. -lft -I libft/. -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C mlx_linux
	$(MAKE) fclean -C libft
fclean: clean
	rm -f $(NAME)

re: fclean all
