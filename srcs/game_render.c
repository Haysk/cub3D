/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:10:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 05:25:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	render_player(t_data *data)
{
	data->color = 0xFFFFFF;
	put_rect(init_rect(data->player.x * TILE_SIZE * data->scale
			+ (TILE_SIZE / 3 * data->scale),
			data->player.y * TILE_SIZE * data->scale
			+ (TILE_SIZE / 3 * data->scale), data->player.width * data->scale,
			data->player.height * data->scale), &data->renderer, data->color);
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
				data->color = 0xFFFFFF;
			else if (data->map[y][x] == '0')
				data->color = 0x000000;
			put_rect(init_rect(x * TILE_SIZE * data->scale,
					y * TILE_SIZE * data->scale, TILE_SIZE * data->scale,
					TILE_SIZE * data->scale), &data->renderer, data->color);
			x++;
		}
		y++;
	}
}

void	game_render(t_data *data)
{
	if (data->renderer.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->renderer.img);
		data->renderer.img = NULL;
	}
	data->renderer.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->renderer.addr = (int *)mlx_get_data_addr(data->renderer.img,
			&data->renderer.bits_per_pixel, &data->renderer.line_length,
			&data->renderer.endian);
	render_map(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->renderer.img, 0, 0);
}
