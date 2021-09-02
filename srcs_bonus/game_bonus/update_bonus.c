/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:12:59 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/02 01:57:02 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	wall_detect(t_data *data, float x, float y, char **map)
{
	int	index_x;
	int	index_y;

	if (x < 0 || x > data->map_width || y < 0 || y > data->map_height)
		return (TRUE);
	index_x = floor(x / TILE_SIZE);
	index_y = floor(y / TILE_SIZE);
	if (index_x >= data->map_x)
		index_x = data->map_x - 1;
	if (index_y >= data->map_y)
		index_y = data->map_y - 1;
	return (map[index_y][index_x] != '0');
}

void	move_player(t_data *data, t_player *player, char **map)
{
	float	new_player_x;
	float	new_player_y;
	float	move_step;
	float	move_side;

	move_step = player->walk_direction * player->walk_speed;
	move_side = player->walk_side_direction * player->walk_speed;
	new_player_x = player->x;
	new_player_y = player->y;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	new_player_x += cos(player->rotation_angle) * move_step
		+ cos(player->rotation_angle + PI / 2) * move_side;
	new_player_y += sin(player->rotation_angle) * move_step
		+ sin(player->rotation_angle + PI / 2) * move_side;
	if (!wall_detect(data, new_player_x, new_player_y, map))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}

void	game_update(t_data *data)
{
	move_player(data, &data->player, data->map);
	cast_all_rays(data, &data->player);
}
