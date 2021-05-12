/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/12 18:27:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	set_res(char **tab, t_resolution *res)
{
	if (res->width < 0)
	{
		if (ft_tablen(tab) == 2 && ft_tabisdigit(tab))
		{
			res->width = ft_atoi(tab[0]);
			res->height = ft_atoi(tab[1]);
			return (TRUE);
		}
		return (ERROR);
	}
	return (FALSE);
}

int	set_colors(char **tab, t_color *colors)
{
	if (colors->red < 0)
	{
		if (ft_tablen(tab) == 3 && ft_tabisdigit(tab))
		{
			colors->red = ft_atoi(tab[0]);
			colors->green = ft_atoi(tab[1]);
			colors->blue = ft_atoi(tab[2]);
			return (TRUE);
		}
		return (ERROR);
	}
	return (FALSE);
}

int	set_textures(char **tab, t_texture *textures)
{
	if (textures->fd < 0)
		if (ft_tablen(tab) == 1)
		{
			textures->path = ft_substr(*tab, 0, ft_strlen(*tab));
			textures->fd = 1;
			return (TRUE);
		}
	return (FALSE);
}

int	tab_funptr(char **tab, t_params *params)
{
	size_t	i;

	i = 0;
	if (!*tab || !tab[1])
		return (ERROR);
	if (ft_strncmp(*tab, params->res->name, ft_strlen(*tab)) == 0)
		return (params->res->set(tab + 1, params->res));
	while (params->colors[i].name)
	{
		if (ft_strncmp(*tab, params->colors[i].name, ft_strlen(*tab) + 1) == 0)
			return (params->colors[i].set(tab + 1, &params->colors[i]));
		i++;
	}
	i = 0;
	while (params->textures[i].name)
	{
		if (ft_strncmp(*tab, params->textures[i].name, ft_strlen(*tab) + 1) == 0)
			return (params->textures[i].set(tab + 1, &params->textures[i]));
		i++;
	}
	return (ERROR);
}

int	set_params(char *line, t_params *params)
{
	char	**tab;
	
	errno = 0;
	if (empty_line(line))
	{
		printf("empty line\n");
		return (EXIT_FAILURE);
	}
	tab = my_split(line, SEPARATORS);
	ft_puttab(tab);
	printf("|%s| |%s|\n", line, *tab);
	printf("\n");
	if (tab_funptr(tab, params) == ERROR)
		printf("ERROR\nset_params : funptr NULL\n\n");
	// params.colors = set_colors(tab, params.colors);
	// params.textures = set_textures(tab, params.textures);
	free_tab(tab);
	if (errno != 0)
	{
		free_all(line, params);
		exit(my_error(errno, NULL));
	}
	return (EXIT_SUCCESS);
}
