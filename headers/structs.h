/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 04:48:28 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_texture
{
	char	*name;
	char	*path;
	int		is_set;
}				t_texture;

typedef struct s_color
{
	char	*name;
	int		red;
	int		green;
	int		blue;
	int		is_set;
}				t_color;

typedef struct s_player
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		is_set;
}				t_player;

typedef struct s_image {
	void	*img;
	int		*addr;
	int		with;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_rect;

typedef struct s_data
{
	int			fd;
	int			map_x;
	int			map_y;
	float		scale;
	int			map_is_set;
	int			params_is_set;
	int			end_file;
	char		*line;
	char		**map;
	t_color		*colors;
	t_texture	*textures;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_player	player;
	t_image		renderer;
	t_rect		rect;
	int			color;
}				t_data;

#endif
