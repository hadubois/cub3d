# ================================[ CONFIG ]================================== #
NAME = cub3d

SRC_DIR    = src
OBJ_DIR    = obj
INC_DIR    = includes
LIBFT_DIR  = lib/libft
LIBGNL_DIR = lib/get_next_line
LIBMLX_DIR = mlx

# Source folders
FREE_DIR     = $(SRC_DIR)/free
INIT_DIR     = $(SRC_DIR)/init_window
KEYHOOK_DIR  = $(SRC_DIR)/key_hook
PARSING_DIR  = $(SRC_DIR)/parsing
PRINT_DIR    = $(SRC_DIR)/print
UTILS_DIR    = $(SRC_DIR)/utils

# Source files
SRC = $(SRC_DIR)/main.c \
	  $(FREE_DIR)/ft_free.c \
	  $(INIT_DIR)/init_window.c \
	  $(KEYHOOK_DIR)/key_hook.c \
	  $(PARSING_DIR)/check_map.c \
	  $(PARSING_DIR)/extract_elements.c \
	  $(PARSING_DIR)/fill_data.c \
	  $(PARSING_DIR)/fill_data_utils.c \
	  $(PARSING_DIR)/parse.c \
	  $(PRINT_DIR)/my_pixel_put.c \
	  $(PRINT_DIR)/print_face.c \
	  $(PRINT_DIR)/print_ray.c \
	  $(UTILS_DIR)/ft_strcmp.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 \
	-I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBGNL_DIR) -I$(LIBMLX_DIR)
MLX_FLAGS = -lX11 -lXext

LIBFT = $(LIBFT_DIR)/libft.a
LIBGNL = $(LIBGNL_DIR)/lib_get_next_line.a
MLX_LIBS = libmlx.a libmlx_Linux.a

MAKEFLAGS += --no-print-directory

# ================================[ DRAWING ]================================= #
RST = \033[0m
G   = \033[32m
UP_LINE   = "┌───────────────────────────┐"
DOWN_LINE = "└───────────────────────────┘"
SIDE_L    = │
L_ARROW   = ❯

# ===============================[ RULES ]==================================== #
all: $(NAME)

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT_DIR)
	@ make -s -C $(LIBGNL_DIR)
	@ make -s -C $(LIBMLX_DIR)
	@ cp $(LIBMLX_DIR)/libmlx.a ./
	@ cp $(LIBMLX_DIR)/libmlx_Linux.a ./
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBGNL) $(MLX_LIBS) $(MLX_FLAGS) -lm -o $(NAME)
	@ printf '\033[H\033[2J'
	@ echo $(UP_LINE)
	@ echo "$(SIDE_L)       $(NAME) [$(G)READY$(RST)]       $(SIDE_L)"
	@ echo $(DOWN_LINE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	@ make clean -s -C $(LIBFT_DIR)
	@ make clean -s -C $(LIBGNL_DIR)
	@ make clean -s -C $(LIBMLX_DIR)
	@ rm -rf $(OBJ_DIR)
	@ echo "$(L_ARROW) clean [$(G)O.K$(RST)]"

fclean: clean
	@ make fclean -s -C $(LIBFT_DIR)
	@ make fclean -s -C $(LIBGNL_DIR)
	@ rm -f $(NAME) $(MLX_LIBS)
	@ echo "$(L_ARROW) fclean [$(G)O.K$(RST)]"

re: fclean all

# =============================[ PHONY TARGETS ]============================== #
.PHONY: all clean fclean re
