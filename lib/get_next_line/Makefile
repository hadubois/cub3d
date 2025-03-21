# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asritz <asritz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 17:49:39 by asritz            #+#    #+#              #
#    Updated: 2024/07/16 17:49:42 by asritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_get_next_line.a

SRC =  get_next_line.c \
	get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :  all clean fclean bonus re

