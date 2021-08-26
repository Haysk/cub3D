/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:00:46 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 01:58:42 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	check_component(t_data *data, int x, int y)
{
	if (!ft_strchr(COMPONENTS, data->map[y][x]))
	{
		return (FALSE);
	}
	if (data->map[y][x] == ' ')
		data->map[y][x] = '1';
	else if (data->map[y][x] && ft_strchr(PLAYER, data->map[y][x]))
	{
		if (!data->player.is_set)
		{
			data->player.x = x;
			data->player.y = y;
			data->map[y][x] = '0';
			data->player.is_set = TRUE;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (!check_component(data, x, y))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	check_horizontally(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x] != '\0')
		x++;
	if (data->map[y][0] != '1' || data->map[y][x - 1] != '1')
		return (FALSE);
	return (TRUE);
}

int	check_vertically(t_data *data, int x)
{
	int	y;
	int start;

	y = 0;
	start = -1;
	while (y < data->map_y)
	{
		if (data->map[y][x] && start < 0)
			start = y;
		if (start >= 0 && (!data->map[y + 1] || data->map[y + 1][x] == '\0')
			&& (data->map[start][x] != '1' || data->map[y][x] != '1'))
			return (FALSE);
		else if (data->map[y + 1] && !data->map[y + 1][x])
			start = -1;
		y++;
	}
	return (TRUE);
}

int	check_borders(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y)
	{
		if (!check_horizontally(data, y))
			return (FALSE);
		y++;
	}
	while (x < data->map_x)
	{
		if (!check_vertically(data, x))
			return (FALSE);
		x++;
	}
	return (TRUE);
}

// int	check_borders(t_data *data, int y)
// {
// 	int	start;
// 	int	end;
// 	int	x;

// 	start = whitespace_size(data->map[y]);
// 	end = ft_strlen(data->map[y]) - end_whitespace_size(data->map[y]);
// 	x = start;
// 	if (data->map[y][start] != WALL || data->map[y][end] != WALL)
// 		return (FALSE);
// 	if (y == 0 || y == data->map_y - 1)
// 		check_borders_top_bottom(data->map[y], start, end);
	
// }
