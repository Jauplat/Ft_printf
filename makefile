# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jauplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 15:53:07 by jauplat           #+#    #+#              #
#    Updated: 2018/05/21 13:12:50 by jauplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OPTION = -o

FILE = 	ft_printf.c ft_attribut.c ft_conversion.c ft_precision.c \
		ft_len.c ft_width.c ft_hex.c ft_string.c ft_char.c ft_octal.c \
		ft_uitoa.c ft_pointer.c

FT =	libft/ft_bzero.c libft/ft_realloc.c \
			libft/ft_putchar.c libft/ft_putendl.c \
			libft/ft_putstr.c libft/ft_putnbr.c \
			libft/ft_strlen.c libft/ft_swap.c \
			libft/ft_strchr.c libft/ft_strrchr.c\
			libft/ft_strcmp.c \
			libft/ft_strcat.c libft/ft_strncat.c libft/ft_strjoin.c \
			libft/ft_strstr.c \
			libft/ft_memcmp.c libft/ft_memset.c libft/ft_memcpy.c \
			libft/ft_memalloc.c libft/ft_memdel.c \
			libft/ft_strdup.c libft/ft_strcpy.c libft/ft_strsub.c \
			libft/ft_strtrim.c \
			libft/ft_atoi.c libft/ft_itoa.c libft/ft_isnegative.c \
			libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c \
			libft/ft_strsplit.c libft/ft_isdigit.c libft/ft_isalpha.c \
			libft/ft_toupper.c

.PHONY: all clean fclean re

OBJ = $(FT:libft/%.c=%.o) $(FILE:%.c=%.o)

all: $(NAME)

%.o: libft/%.c
	gcc $(FLAG) $(OPTION) $@ -c $<

%.o: %.c
	gcc $(FLAG) $(OPTION) $@ -c $<

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
		rm -rf libft/libft.a
re:
	make fclean
	make
