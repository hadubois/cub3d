NAME = cub3d

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCDIR) -Ilib/libft -Ilib/get_next_line -g3
MLX_FLAGS	=	-lX11 -lXext
MAKEFLAGS	+= --no-print-directory

OBJDIR = obj
INCDIR = includes

LIB = lib/libft/libft.a lib/get_next_line/lib_get_next_line.a

SRC_MAIN = 		src/main.c

SRC_PARSING =	src/parsing/parse.c \
				src/parsing/map_reader.c \
				src/parsing/fill_data.c \
				src/parsing/check_map.c \
				src/parsing/parsing_utils.c

SRC_FREE =		src/free/ft_free.c 

SRC_MLX_INIT = 	src/init_window/init_window.c

SRC_RAYCAST = 	src/key_hook/key_hook.c \
				src/print/print_ray.c \
				src/print/print_face.c \
				src/print/my_pixel_put.c

SRC = $(SRC_MAIN) $(SRC_PARSING) $(SRC_FREE) $(SRC_MLX_INIT) $(SRC_RAYCAST)
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

RST = \033[0m
G = \033[32m
L_ARROW   = ❯

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@ mkdir -p $(OBJDIR) || true

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -MMD -MP -c $< -o $@

lib: FORCE
	@ make -C lib/libft
	@ make -C lib/get_next_line

FORCE:

-include $(OBJ:.o=.d)

$(NAME): lib $(OBJ)
	@ make -C mlx
	@ cp mlx/libmlx.a ./
	@ cp mlx/libmlx_Linux.a ./
	@ $(CC) $(CFLAGS) $(OBJ) libmlx.a libmlx_Linux.a $(LIB) $(MLX_FLAGS) -lm -o $(NAME)
	@ echo "$(L_ARROW) cub3d $(G)READY$(RST)"

clean:
	@ make clean -C mlx
	@ make clean -C lib/libft
	@ make clean -C lib/get_next_line
	@ rm -rf $(OBJDIR)
	@ echo "$(L_ARROW) clean $(G)O.K$(RST)"

fclean: clean
	@ make clean -C mlx
	@ make fclean -C lib/libft
	@ make fclean -C lib/get_next_line
	@ rm -f libmlx.a libmlx_Linux.a $(NAME)
	@ echo "$(L_ARROW) fclean $(G)O.K$(RST)"

re: fclean all

.PHONY: all clean fclean re
