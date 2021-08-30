/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 01:45:42 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/30 03:30:07 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	my_put_pixel(t_image *renderer, int x, int y, int color)
{
	renderer->addr[y * renderer->line_length / 4 + x] = color;
}

void	put_line(t_line line, t_image *renderer, int color)
{
	int	stop;

	stop = FALSE;
	while (!stop)
	{
		my_put_pixel(renderer, line.xa, line.ya, color);
		if (line.xa == line.xb && line.ya == line.yb)
			stop = TRUE;
		if (!stop)
		{
			line.e2 = line.err;
			if (line.e2 > -line.dx)
			{
				line.err -= line.dy;
				line.xa += line.sx;
			}
			if (line.e2 < line.dy)
			{
				line.err += line.dx;
				line.ya += line.sy;
			}
		}
	}
}

void	put_rect(t_rect rect, t_image *renderer, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.width)
	{
		j = 0;
		while (j < rect.height)
		{
			my_put_pixel(renderer, rect.x + j,
				rect.y + i, color);
			j++;
		}
		i++;
	}
}

void	put_texture(t_data *data, int i, int j)
{
	int	tex_x;
	int	tex_y;
	int	dist_top;

	if (data->rays[i].hit_vertical)
		tex_x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
	else
		tex_x = (int)data->rays[i].wall_hit_x % TILE_SIZE;
	while (j < data->wall.bottom_pixel)
	{
		dist_top = j + (data->wall.strip_height / 2) - (data->win_height / 2);
		tex_y = dist_top
			* ((float)data->textures[0].height / data->wall.strip_height);
		data->renderer.addr[j * data->renderer.line_length / 4 + i]
			= data->textures[0].addr[tex_y
			* data->textures[0].line_length / 4 + tex_x];
		j++;
	}
}
