NAME = cube3d

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(INCDIR) -Ilib/libft -Ilib/get_next_line -g3
MLX_FLAGS	=	-lX11 -lXext

OBJDIR = obj
INCDIR = includes

LIB = lib/libft/libft.a lib/get_next_line/lib_get_next_line.a

SRC_MAIN = 		src/main.c

SRC_PARSING =	src/parsing/parse.c \
				src/parsing/map_reader.c \
				src/parsing/fill_data.c \
				src/parsing/check_map.c

SRC_FREE =		src/free/ft_free.c src/print/print_minimap.c

SRC_MLX_INIT = 	src/init_window/init_window.c

SRC = $(SRC_MAIN) $(SRC_PARSING) $(SRC_FREE) $(SRC_MLX_INIT)
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR) || true

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

lib: FORCE
	make -C lib/libft
	make -C lib/get_next_line

FORCE:

-include $(OBJ:.o=.d)

$(NAME): lib $(OBJ)
	make -C mlx
	cp mlx/libmlx.a ./
	cp mlx/libmlx_Linux.a ./
	$(CC) $(CFLAGS) $(OBJ) libmlx.a libmlx_Linux.a $(LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C mlx
	make clean -C lib/libft
	make clean -C lib/get_next_line
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C lib/libft
	make fclean -C lib/get_next_line
	rm -f libmlx.a libmlx_Linux.a $(NAME)

re: fclean all

.PHONY: all clean fclean re