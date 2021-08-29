/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 01:45:42 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/29 02:43:31 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_rect	my_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

t_line	my_line(int xa, int ya, int xb, int yb)
{
	t_line	line;

	line.xa = xa;
	line.ya = ya;
	line.xb = xb;
	line.yb = yb;
	line.dx = ft_abs(line.xb - line.xa);
	line.dy = ft_abs(line.yb - line.ya);
	line.sx = -1;
	if (line.xa < line.xb)
		line.sx = 1;
	line.sy = -1;
	if (line.ya < line.yb)
		line.sy = 1;
	line.err = -line.dy / 2;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	line.e2 = 0;
	return (line);
}

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
