/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_is_setialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 00:08:55 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_data	new_data(int fd)
{
	t_data	data;
	
	data.fd = fd;
	data.params_is_set = FALSE;
	data.player.is_set = FALSE;
	data.map_is_set = FALSE;
	data.end_file = FALSE;
	data.line = NULL;
	data.map_x = 0;
	data.map_y = 0;
	data.map = NULL;
	data.player.x = 0;
	data.player.y = 0;
	data.colors = init_colors();
	data.textures = init_textures();
	return (data);
}

t_color	*init_colors(void)
{
	static t_color	colors[3] = {
		{.name = "C", .red = -1, .green = -1, .blue = -1, .is_set = 0},
		{.name = "F", .red = -1, .green = -1, .blue = -1, .is_set = 0},
		{NULL}
	};
	return (colors);
}

t_texture	*init_textures(void)
{
	static t_texture	textures[6] = {
		{.name = "NO", .path = NULL, .is_set = 0},
		{.name = "SO", .path = NULL, .is_set = 0},
		{.name = "EA", .path = NULL, .is_set = 0},
		{.name = "WE", .path = NULL, .is_set = 0},
		{NULL}
	};
	return (textures);
}

int	print_params(t_data data)
{
	printf("fd : %i\n\n", data.fd);
	while (data.colors->name)
	{
		printf("colors : %s\n\tred : %i\n\tgreen : %i\n\tblue : %i\n\n",
			data.colors->name, data.colors->red,
			data.colors->green, data.colors->blue);
		data.colors++;
	}
	while (data.textures->name)
	{
		printf("textures : %s\n\tpath : %s\n\tfd : %i\n\n",
			data.textures->name, data.textures->path, data.textures->is_set);
		data.textures++;
	}
	return (TRUE);
}

void	check_params(t_data *data)
{
	if (!data->params_is_set || !data->end_file || !data->map_is_set)
	{
		free_all(data);
		if (!data->params_is_set)
			exit(my_error(4, ""));
		if (!data->end_file || !data->map_is_set)
			exit(my_error(5, ""));
	}
}
