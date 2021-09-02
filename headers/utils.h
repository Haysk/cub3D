/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:30:54 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/01 17:30:32 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"

# define PI 3.14159265
# define TWO_PI 6.28318530
# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
# define COMPONENTS " 01NSEW"
# define PLAYER "NSEW"
# define WALL '1'
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361

size_t		ft_tablen(char **tab);
size_t		ft_intlen(int nbr);

int			ft_findchar(char *str, char c);
char		**my_split(char const *str, char *cutter);

char		*ft_strjoin_gnl(char *s1, char *s2);
int			get_next_line(int fd, char **line);

int			check_file_extension(char *path, char *str);
size_t		whitespace_size(const char *str);
int			empty_line(char *str);
int			int_to_trgb(int t, int r, int g, int b);
int			get_color(t_data *data, char *name);
t_texture	*get_texture(t_data *data, char *name);

#endif
