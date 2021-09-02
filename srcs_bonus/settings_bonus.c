/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/02 14:10:13 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	set_colors(char **tab, t_color *colors)
{
	if (!colors->is_set)
	{
		if (ft_tablen(tab) == 3 && ft_tabisdigit(tab))
		{
			colors->red = ft_atoi(tab[0]);
			colors->green = ft_atoi(tab[1]);
			colors->blue = ft_atoi(tab[2]);
			if (colors->red > 255 || colors->green > 255
				|| colors->blue > 255)
				return (FALSE);
			colors->is_set = 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	set_textures(char **tab, t_texture *textures)
{
	if (!textures->is_set)
	{
		if (ft_tablen(tab) == 1)
		{
			textures->path = ft_substr(*tab, 0, ft_strlen(*tab));
			textures->is_set = 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	tab_funptr(char **tab, t_data *data)
{
	size_t	i;

	i = 0;
	if (!*tab || !tab[1])
		return (FALSE);
	while (data->colors[i].name)
	{
		if (ft_strncmp(*tab, data->colors[i].name, ft_strlen(*tab) + 1) == 0)
			return (set_colors(tab + 1, &data->colors[i]));
		i++;
	}
	i = 0;
	while (data->textures[i].name)
	{
		if (ft_strncmp(*tab, data->textures[i].name, ft_strlen(*tab) + 1) == 0)
			return (set_textures(tab + 1, &data->textures[i]));
		i++;
	}
	return (FALSE);
}

int	set_params(t_data *data)
{
	char	**tab;

	tab = my_split(data->line, SEPARATORS);
	if (!tab_funptr(tab, data))
	{
		ft_freetab(tab);
		return (FALSE);
	}
	ft_freetab(tab);
	return (TRUE);
}

int	params_is_set(t_data data)
{
	int	i;

	i = 0;
	while (data.colors[i].name)
	{
		if (data.colors[i].is_set == 0)
			return (FALSE);
		i++;
	}
	i = 0;
	while (data.textures[i].name)
	{
		if (data.textures[i].is_set == 0)
			return (FALSE);
		i++;
	}
	i = 0;
	return (TRUE);
}
