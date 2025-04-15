# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asritz <asritz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:18:52 by asritz            #+#    #+#              #
#    Updated: 2025/04/15 11:55:32 by hadubois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf.c \
	ft_putchar_fd_print.c \
	ft_putstr_fd_print.c \
	ft_putnbr_fd_print.c \
	ft_putunbr_fd_print.c \
	ft_putptr.c \
	ft_putupp_hexa.c \
	ft_putlow_hexa.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

AR = ar rcs


all : $(NAME)

$(NAME) : $(OBJ)
	@ $(AR) $@ $^

%.o : %.c
	@ $(CC) $(CFLAGS) -c $<

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
