# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouay <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 20:53:27 by adouay            #+#    #+#              #
#    Updated: 2022/08/29 06:51:32 by adouay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_B = libft_base.a

GNL = gnl/gnl.a

FT_PRINTF = ft_printf/ft_printf.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_split.c \
    ft_strchr.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c

BONUS_SRC = ft_lstnew_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstsize_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ft_printf
	@$(MAKE) -C gnl
	ar rc $(LIBFT_B) $^
	ar rcT $(NAME) $(LIBFT_B) $(GNL) $(FT_PRINTF)

%.o : %.c
	$(CC) -c $^

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^

clean :
	@$(MAKE) fclean -C ft_printf
	@$(MAKE) fclean -C gnl
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(LIBFT_B)
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
