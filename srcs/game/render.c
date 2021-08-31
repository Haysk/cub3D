/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:10:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/31 18:56:38 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	render_player(t_data *data, t_player *player)
{
	t_rect	rect;
	t_line	line;

	rect = my_rect(player->x * data->scale, player->y * data->scale,
			player->width * data->scale, player->height * data->scale);
	line = my_line(player->x * data->scale, player->y * data->scale,
			data->scale * player->x + cos(player->rotation_angle) * 15,
			data->scale * player->y + sin(player->rotation_angle) * 15);
	put_rect(rect, &data->renderer, 0xFFFFFF);
	put_line(line, &data->renderer, 0xFFFFFF);
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map[y][x] == '1')
				put_rect(my_rect(x * TILE_SIZE * data->scale,
					y * TILE_SIZE * data->scale, TILE_SIZE * data->scale,
					TILE_SIZE * data->scale), &data->renderer, 0xFFFFFF);
			else if (data->map[y][x] == '0')
				put_rect(my_rect(x * TILE_SIZE * data->scale,
					y * TILE_SIZE * data->scale, TILE_SIZE * data->scale,
					TILE_SIZE * data->scale), &data->renderer, 0x000000);
			x++;
		}
		y++;
	}
}

void	render_rays(t_data *data, t_player *player)
{
	int		ray_num;
	t_line	line;
	float	x;
	float	y;

	ray_num = 0;
	while (ray_num < data->rays_num)
	{
		x = data->rays[ray_num].wall_hit_x * data->scale;
		y = data->rays[ray_num].wall_hit_y * data->scale;
		line = my_line(player->x * data->scale, player->y * data->scale,
				(int)x, (int)y);
		put_line(line, &data->renderer, 0xFF0000);
		ray_num++;
	}
}

void	game_render(t_data *data)
{
	if (data->renderer.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->renderer.img);
		data->renderer.img = NULL;
	}
	data->renderer.img = mlx_new_image(data->mlx,
			data->win_width, data->win_height);
	data->renderer.addr = (int *)mlx_get_data_addr(data->renderer.img,
			&data->renderer.bits_per_pixel, &data->renderer.line_length,
			&data->renderer.endian);
	render_walls(data, data->rays);
	render_map(data);
	render_rays(data, &data->player);
	render_player(data, &data->player);
	mlx_put_image_to_window(data->mlx, data->win, data->renderer.img, 0, 0);
}
