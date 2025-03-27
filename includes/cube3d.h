/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:19 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 18:00:46 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

// INCLUDES ------------------------------------------------

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ALIASES ------------------------------------------------

// KEYBINDS

# define FORWARD 0
# define BACKWARD 1
# define LEFT 2
# define RIGHT 3

// ERROR MESSAGES

# define WRONG_MAP_EXT printf("Error\ninvalid file: wrong map extension\n")
# define WRONG_NUMBER_ARG printf("Error\nwrong number of arguments\n")
# define ERROR_OPEN printf("Error\ninvalid file: the file does not exist\n")
# define EMPTY_MAP_FILE printf("Error\ninvalid file: the map file is empty\n")
# define ERROR_MALLOC printf("Error\na malloc failed\n")
# define WRONG_IDENTIFIER printf("Error\ninvalid map: identifiers in the map are not valid\n")
# define EMPTY_MAP printf("Error\ninvalid map: the map is empty\n")
# define INVALID_CHAR printf("Error\ninvalid map: unexpected char in color\n")
# define OUT_OF_SCALE_COLOR printf("Error\ninvalid map: color's value out of bound\n")
# define INVALID_VALUES printf("Error\ninvalid map: unknown char in the map\n")
# define MULTIPLE_START printf("Error\ninvalid map: multiple or no start points\n")
# define INVALID_BORDERS printf("Error\ninvalid map: map isn't correctly closed\n")
# define MLX_FAIL printf("Error\nmlx: an error occured during mlx initialization\n")
# define MLX_IMG_FAIL printf("Error\nmlx: conversion to image failed\n")

// SCREEN SHIT

# define SC_HEI 900 
# define SC_WID 1600

// STRUCTURES ----------------------------------------------

typedef struct s_coo
{
	int 	x;
	int 	y;
}			t_coo;

typedef struct s_sprite
{
	char	*path;
	void	*addr;
}			t_sprite;

typedef struct s_data
{
	t_sprite	no;
	t_sprite	so;
	t_sprite	we;
	t_sprite	ea;
	int		f[3];
	int		c[3];
	char	**map;
	void	*mlx;
	void	*win;
	void	*win_rcst;
	int		width;
	int		height;
	t_coo	map_size;
	float	player_angle;
	t_coo	player;
}			t_data;

// PROTOTYPES ----------------------------------------------

// PARSING

bool		parse(char *map_file, t_data *data);
bool		check_map_format(char *map_file);
char		*open_map(char *map_file);
bool		fill_data(char *map_content, t_data *data);
bool		check_map(t_data *data);

// MLX INIT

bool		init_window(t_data *data);

// FREE

void		free_tab(void **tab);
void		free_data(t_data *data);
int			close_mlx(t_data *data);
int			close_mlx_error(t_data *data);

// TMP

void	print_minimap(t_data *data);

// KEY HOOKS

int	key_hook(int keycode, t_data *data);

#endif