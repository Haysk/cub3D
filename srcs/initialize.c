/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/11 21:27:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_params	new_params(void)
{
	t_params	params;
	
	params.fd = 0;
	params.res = init_resolution();
	params.colors = init_colors();
	params.textures = init_textures();
	return (params);
}

t_resolution	*init_resolution(void)
{
	static t_resolution	res[2] = {
		{.name = "R", .width = -1, .height = -1, .set = set_res},
		{.name = NULL, .width = -1, .height = -1, .set = NULL}
	};
	return (res);
}

t_color	*init_colors(void)
{
	static t_color	colors[3] = {
		{.name = "C", .red = -1, .green = -1, .blue = -1, .set = set_colors},
		{.name = "F", .red = -1, .green = -1, .blue = -1, .set = set_colors},
		{.name = NULL, .red = -1, .green = -1, .blue = -1, .set = NULL}
	};
	return (colors);
}

t_texture	*init_textures(void)
{
	static t_texture	textures[6] = {
		{.name = "NO", .path = NULL, .fd = -1, .set = set_textures},
		{.name = "SO", .path = NULL, .fd = -1, .set = set_textures},
		{.name = "EA", .path = NULL, .fd = -1, .set = set_textures},
		{.name = "WE", .path = NULL, .fd = -1, .set = set_textures},
		{.name = "S", .path = NULL, .fd = -1, .set = set_textures},
		{.name = NULL, .path = NULL, .fd = -1, .set = NULL}
	};
	return (textures);
}

int	print_params(t_params params)
{
	printf("fd : %i\n\n", params.fd);
	printf("resolution :\n\twidth : %i\n\theight : %i\n\n",
		params.res->width, params.res->height);
	while (params.colors->name)
	{
		printf("colors : %s\n\tred : %i\n\tgreen : %i\n\tblue : %i\n\n",
			params.colors->name, params.colors->red,
			params.colors->green, params.colors->blue);
		params.colors++;
	}
	while (params.textures->name)
	{
		printf("textures : %s\n\tpath : %s\n\tfd : %i\n\n",
			params.textures->name, params.textures->path, params.textures->fd);
		params.textures++;
	}
	return (EXIT_SUCCESS);
}
