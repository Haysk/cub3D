/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 04:43:38 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 04:53:16 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_rect	init_rect(int x, int y, int width, int height)
{
	t_rect rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

void	my_put_pixel(t_image *renderer, int x, int y, int color)
{
	renderer->addr[y * renderer->line_length / 4 + x] = color;
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
