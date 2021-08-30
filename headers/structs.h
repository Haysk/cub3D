/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/30 01:14:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_texture
{
	char	*name;
	char	*path;
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_rect;

typedef struct s_line
{
	int	xa;
	int	ya;
	int	xb;
	int	yb;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_line;

typedef struct s_image {
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		is_set;
}				t_player;

typedef struct s_face
{
	int		up;
	int		down;
	int		left;
	int		right;
}				t_face;
typedef struct s_inter
{
	float	intercept_x;
	float	intercept_y;
	float	step_x;
	float	step_y;
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	float	wall_content;
	float	next_touch_x;
	float	next_touch_y;
	float	hit_distance;
}				t_inter;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		hit_vertical;
	t_face	face;
	int		wall_hit_content;
}				t_ray;

typedef struct s_wall
{
	float	perp_dist;
	float	proj_plane_dist;
	float	proj_wall_height;
	int		strip_height;
	int		top_pixel;
	int		bottom_pixel;
}				t_wall;

typedef struct s_data
{
	int			fd;
	int			map_is_set;
	int			params_is_set;
	char		*line;
	int			end_file;
	char		**map;
	int			map_x;
	int			map_y;
	float		scale;
	int			color;
	t_color		*colors;
	t_texture	*textures;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	float		fov;
	t_rect		rect;
	t_player	player;
	t_image		renderer;
	t_wall		wall;
	float		rays_angle;
	int			rays_num;
	int			rays_id;
	t_ray		*rays;
}				t_data;

#endif
