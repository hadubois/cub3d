/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:19 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/24 15:16:26 by aule-bre         ###   ########.fr       */
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
# define WATCH_LEFT 4
# define WATCH_RIGHT 5

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
# define MULTIPLE_START printf("Error\ninvalid map: multiple start points\n")
# define INVALID_BORDERS printf("Error\ninvalid map: map isn't correctly closed\n")

// STRUCTURES ----------------------------------------------

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	orientation;
	char	**map;
}			t_data;

// PROTOTYPES ----------------------------------------------

// PARSING

bool		parse(char *map_file, t_data *data);
bool		check_map_format(char *map_file);
char		*open_map(char *map_file);
bool		fill_data(char *map_content, t_data *data);
bool		check_map(t_data *data);

// FREE

void		free_tab(void **tab);
void		free_data(t_data *data);

#endif