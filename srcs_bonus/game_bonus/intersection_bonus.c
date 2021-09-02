/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:43:26 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/27 17:45:24 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	inter_wall_detect(t_data *data, int check_x, int check_y, t_inter *axe)
{	
	int	x;
	int	y;

	if (wall_detect(data, check_x, check_y, data->map))
	{
		axe->wall_hit_x = axe->next_touch_x;
		axe->wall_hit_y = axe->next_touch_y;
		y = (int)floor(check_y / TILE_SIZE);
		if (y >= data->map_y)
			y = data->map_y - 1;
		x = (int)floor(check_x / TILE_SIZE);
		if (x >= data->map_y)
			x = data->map_y - 1;
		axe->found_wall_hit = TRUE;
		return (TRUE);
	}
	axe->next_touch_x += axe->step_x;
	axe->next_touch_y += axe->step_y;
	return (FALSE);
}

void	init_horizontal(t_data *data, t_inter *horiz, t_face face)
{
	horiz->found_wall_hit = FALSE;
	horiz->wall_hit_x = 0;
	horiz->wall_hit_y = 0;
	horiz->intercept_y = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (face.down)
		horiz->intercept_y += TILE_SIZE;
	horiz->intercept_x = data->player.x + (horiz->intercept_y - data->player.y)
		/ tan(data->rays_angle);
	horiz->step_y = TILE_SIZE;
	if (face.up)
		horiz->step_y *= -1;
	horiz->step_x = TILE_SIZE / tan(data->rays_angle);
	if (face.left && horiz->step_x > 0)
		horiz->step_x *= -1;
	if (face.right && horiz->step_x < 0)
		horiz->step_x *= -1;
	horiz->next_touch_x = horiz->intercept_x;
	horiz->next_touch_y = horiz->intercept_y;
}

t_inter	horizontal_inter(t_data *data, t_face face)
{
	t_inter	horiz;
	float	check_x;
	float	check_y;
	int		wall;

	wall = FALSE;
	init_horizontal(data, &horiz, face);
	while (!wall && horiz.next_touch_x >= 0
		&& horiz.next_touch_x <= data->map_width
		&& horiz.next_touch_y >= 0 && horiz.next_touch_y <= data->map_height)
	{
		check_x = horiz.next_touch_x;
		check_y = horiz.next_touch_y;
		if (face.up)
			check_y += -1;
		wall = inter_wall_detect(data, check_x, check_y, &horiz);
	}
	return (horiz);
}

void	init_vertical(t_data *data, t_inter *verti, t_face face)
{
	verti->found_wall_hit = FALSE;
	verti->wall_hit_x = 0;
	verti->wall_hit_y = 0;
	verti->intercept_x = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (face.right)
		verti->intercept_x += TILE_SIZE;
	verti->intercept_y = data->player.y + (verti->intercept_x - data->player.x)
		* tan(data->rays_angle);
	verti->step_x = TILE_SIZE;
	if (face.left)
		verti->step_x *= -1;
	verti->step_y = TILE_SIZE * tan(data->rays_angle);
	if (face.up && verti->step_y > 0)
		verti->step_y *= -1;
	if (face.down && verti->step_y < 0)
		verti->step_y *= -1;
	verti->next_touch_x = verti->intercept_x;
	verti->next_touch_y = verti->intercept_y;
}

t_inter	vertical_inter(t_data *data, t_face face)
{
	t_inter	verti;
	float	check_x;
	float	check_y;
	int		wall;

	init_vertical(data, &verti, face);
	wall = FALSE;
	while (!wall && verti.next_touch_x >= 0
		&& verti.next_touch_x <= data->map_width
		&& verti.next_touch_y >= 0 && verti.next_touch_y <= data->map_height)
	{
		check_x = verti.next_touch_x;
		if (face.left)
			check_x += -1;
		check_y = verti.next_touch_y;
		wall = inter_wall_detect(data, check_x, check_y, &verti);
	}
	return (verti);
}
