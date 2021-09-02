/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:10:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/01 16:50:38 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

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
	mlx_put_image_to_window(data->mlx, data->win, data->renderer.img, 0, 0);
}
