/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:48:25 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/30 01:34:26 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	set_ray(t_data *data, t_inter horiz, t_inter verti, t_face ray_facing)
{
	if (verti.hit_distance < horiz.hit_distance)
	{
		data->rays[data->rays_id].distance = verti.hit_distance;
		data->rays[data->rays_id].wall_hit_x = verti.wall_hit_x;
		data->rays[data->rays_id].wall_hit_y = verti.wall_hit_y;
		data->rays[data->rays_id].wall_hit_content = verti.wall_content;
		data->rays[data->rays_id].hit_vertical = TRUE;
	}
	else
	{
		data->rays[data->rays_id].distance = horiz.hit_distance;
		data->rays[data->rays_id].wall_hit_x = horiz.wall_hit_x;
		data->rays[data->rays_id].wall_hit_y = horiz.wall_hit_y;
		data->rays[data->rays_id].wall_hit_content = horiz.wall_content;
		data->rays[data->rays_id].hit_vertical = FALSE;
	}
	data->rays[data->rays_id].ray_angle = data->rays_angle;
	data->rays[data->rays_id].face.down = ray_facing.down;
	data->rays[data->rays_id].face.up = ray_facing.up;
	data->rays[data->rays_id].face.left = ray_facing.left;
	data->rays[data->rays_id].face.right = ray_facing.right;
}

void	cast_ray(t_data *data, t_player *player)
{
	t_face	ray_facing;
	t_inter	horiz;
	t_inter	verti;

	data->rays_angle = normalize_angle(data->rays_angle);
	ray_facing.down = data->rays_angle > 0 && data->rays_angle < PI;
	ray_facing.up = !ray_facing.down;
	ray_facing.right = data->rays_angle < 0.5 * PI
		|| data->rays_angle > 1.5 * PI;
	ray_facing.left = !ray_facing.right;
	horiz = horizontal_inter(data, ray_facing);
	verti = vertical_inter(data, ray_facing);
	if (horiz.found_wall_hit)
		horiz.hit_distance = distance_between_points(player->x, player->y,
				horiz.wall_hit_x, horiz.wall_hit_y);
	else
		horiz.hit_distance = FLT_MAX;
	if (verti.found_wall_hit)
		verti.hit_distance = distance_between_points(player->x, player->y,
				verti.wall_hit_x, verti.wall_hit_y);
	else
		verti.hit_distance = FLT_MAX;
	set_ray(data, horiz, verti, ray_facing);
}

void	cast_all_rays(t_data *data, t_player *player)
{
	data->rays_id = 0;
	data->rays_angle = player->rotation_angle - (data->fov / 2);
	while (data->rays_id < data->rays_num)
	{
		cast_ray(data, player);
		data->rays_angle += data->fov / data->win_width;
		data->rays_id++;
	}
}
