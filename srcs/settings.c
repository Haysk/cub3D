/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/07 01:09:22 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_resolution	set_res(char *line, t_resolution res)
{
	size_t	i;

	i = whitespace_size(line);
	if (line[i] == 'R')
	{
		res.width = 1;
		res.height = 1;
		printf("set_resolution : %s\n", line);
		res = parse_res(line + i + 1, res);
		return (res);
	}
	return (res);
}

t_color	*set_colors(char *line, t_color *colors)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = whitespace_size(line);
	while (colors[i].name)
	{
		if (ft_memcmp(line + j, colors[i].name, 1) == EXIT_SUCCESS)
		{
			colors[i].red = 1;
			colors[i].green = 1;
			colors[i].blue = 1;
			printf("find_color : %s\n", line);
			return (colors);
		}
		i++;
	}
	return (colors);
}

t_texture	*set_textures(char *line, t_texture *textures)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = whitespace_size(line);
	while (textures[i].name)
	{
		if (ft_memcmp(line + j, textures[i].name,
				ft_strlen(textures[i].name)) == EXIT_SUCCESS)
		{
			textures[i].path = "trouve";
			textures[i].fd = 1;
			printf("find_texture : %s\n", line);
			return (textures);
		}
		i++;
	}
	return (textures);
}

t_params	set_params(char *line, t_params params)
{
	errno = 0;
	params.res = set_res(line, params.res);
	params.colors = set_colors(line, params.colors);
	params.textures = set_textures(line, params.textures);
	if (errno != 0)
	{
		printf("free all\n");
		close(params.fd);
		free(line);
		exit(EXIT_FAILURE);
	}
	return (params);
}
