/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:13:48 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/29 03:00:02 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	new_player(t_player *player)
{
	player->x *= TILE_SIZE;
	player->y *= TILE_SIZE;
	player->width = 1;
	player->height = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	if ((char)player->rotation_angle == 'E')
		player->rotation_angle = 0;
	if ((char)player->rotation_angle == 'S')
		player->rotation_angle = 1;
	if ((char)player->rotation_angle == 'W')
		player->rotation_angle = 2;
	if ((char)player->rotation_angle == 'N')
		player->rotation_angle = 3;
	player->rotation_angle *= PI / 2;
	player->walk_speed = 2;
	player->turn_speed = 1.5 * (PI / 180);
}

void	game_setup(t_data *data)
{
	data->win_width = data->map_x * TILE_SIZE;
	data->win_height = data->map_y * TILE_SIZE;
	data->scale = 0.5;
	data->fov = 60 * (PI / 180);
	data->renderer.img = NULL;
	data->rays_num = data->win_height;
	data->rays = ft_calloc(data->rays_num + 1, sizeof(t_ray));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	new_player(&data->player);
}
