/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:21:45 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 01:59:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	add_line_map(t_data *data)
{
	char	**map;
	int	i;

	i = 0;
	map = ft_calloc(data->map_y + 1, sizeof(char *));
	while (i < data->map_y)
	{
		map[i] = ft_calloc(data->map_x + 1, sizeof(char *));
		if (i < data->map_y - 1)
			ft_strlcpy(map[i], data->map[i], data->map_x + 1);
		else
			ft_strlcpy(map[i], data->line, data->map_x + 1);
		i++;
	}
	ft_freetab(data->map);
	data->map = map;
	return (TRUE);
}

int	get_map(t_data *data)
{
	while (get_next_line(data->fd, &data->line) && empty_line(data->line));
	while (!data->end_file)
	{
		if (!data->line || !*data->line)
			return (FALSE);
		if ((size_t)data->map_x < ft_strlen(data->line))
			data->map_x = ft_strlen(data->line);
		data->map_y++;
		add_line_map(data);
		data->end_file = !get_next_line(data->fd, &data->line);
	}
	if (!check_map(data) || !check_borders(data))
		return (FALSE);
	ft_puttab(data->map);
	return (TRUE);
}
