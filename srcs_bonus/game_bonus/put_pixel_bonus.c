/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 01:45:42 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/01 16:57:16 by adylewsk         ###   ########.fr       */
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
	int			tex_x;
	int			tex_y;
	int			dist_top;
	t_texture	*texture;

	if (data->rays[i].hit_vertical)
		tex_x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
	else
		tex_x = (int)data->rays[i].wall_hit_x % TILE_SIZE;
	if (!data->rays[i].hit_vertical && data->rays[i].face.down)
		texture = get_texture(data, "NO");
	else if (!data->rays[i].hit_vertical && data->rays[i].face.up)
		texture = get_texture(data, "SO");
	else if (data->rays[i].face.right)
		texture = get_texture(data, "WE");
	else
		texture = get_texture(data, "EA");
	while (j < data->wall.bottom_pixel)
	{
		dist_top = j + (data->wall.strip_height / 2) - (data->win_height / 2);
		tex_y = dist_top * ((float)texture->height / data->wall.strip_height);
		data->renderer.addr[j * data->renderer.line_length / 4 + i]
			= texture->addr[tex_y * texture->line_length / 4 + tex_x];
		j++;
	}
}
