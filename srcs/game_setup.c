/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:13:48 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 05:25:41 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	game_setup(t_data *data)
{
	data->win_width = data->map_x * TILE_SIZE;
	data->win_height = data->map_y * TILE_SIZE;
	data->scale = 0.3;
	data->renderer.img = NULL;
	data->player.width = 5;
	data->player.height = 5;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_angle = PI / 2;
	data->player.walk_speed = 100;
	data->player.turn_speed = 45 * (PI / 180);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "cub3D");
}
