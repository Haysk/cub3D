/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:04:15 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/31 17:47:57 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

size_t	whitespace_size(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] && ft_strchr(WHITESPACES, str[i]))
		i++;
	return (i);
}

int	empty_line(char *str)
{
	if (!str || !*str)
		return (TRUE);
	if (whitespace_size(str) == ft_strlen(str))
		return (TRUE);
	return (FALSE);
}

int	int_to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(t_data *data, char *name)
{
	int	i;

	i = 0;
	while (data->colors[i].name)
	{
		if (!ft_strncmp(name, data->colors[i].name, ft_strlen(name) + 1))
			return (int_to_trgb(255, data->colors[i].red,
					data->colors[i].green, data->colors[i].blue));
		i++;
	}
	return (0);
}

t_texture	*get_texture(t_data *data, char *name)
{
	int	i;

	i = 0;
	while(data->textures[i].name)
	{
		if (!ft_strncmp(name, data->textures[i].name, ft_strlen(name) + 1))
			return (&data->textures[i]);
		i++;
	}
	return (NULL);
}
