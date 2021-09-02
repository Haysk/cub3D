/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:01:19 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/31 19:01:19 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	set_wall(t_data *data, t_ray *rays, t_wall *wall, int i)
{
	wall->perp_dist = rays[i].distance
		* cos(rays[i].ray_angle - data->player.rotation_angle);
	if (wall->perp_dist <= 0)
		wall->perp_dist = 1;
	wall->proj_plane_dist = (data->win_width / 2) / tan(data->fov / 2);
	wall->proj_wall_height = (TILE_SIZE / wall->perp_dist)
		* wall->proj_plane_dist;
	wall->strip_height = wall->proj_wall_height;
	wall->top_pixel = (data->win_height / 2) - (wall->strip_height / 2);
	if (wall->top_pixel < 0)
		wall->top_pixel = 0;
	wall->bottom_pixel = (data->win_height / 2) + (wall->strip_height / 2);
	if (wall->bottom_pixel > data->win_height)
		wall->bottom_pixel = data->win_height;
	return (wall->top_pixel);
}

void	render_floor(t_data *data, int bottom_pixel, int i)
{
	int	j;

	j = bottom_pixel;
	while (j < data->win_height)
	{
		my_put_pixel(&data->renderer, i, j, get_color(data, "F"));
		j++;
	}
}

void	render_celling(t_data *data, int top_pixel, int i)
{
	int	j;

	j = 0;
	while (j < top_pixel)
	{
		my_put_pixel(&data->renderer, i, j, get_color(data, "C"));
		j++;
	}
}

void	render_walls(t_data *data, t_ray *rays)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rays_num)
	{
		j = set_wall(data, rays, &data->wall, i);
		render_celling(data, j, i);
		put_texture(data, i, j);
		render_floor(data, data->wall.bottom_pixel, i);
		i++;
	}
}
