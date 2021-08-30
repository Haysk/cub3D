/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:36 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/30 00:38:27 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	free_textures(t_data *data)
{
	while (data->textures->name)
	{
		if (data->textures->path != NULL)
			free(data->textures->path);
		if (data->textures->img)
			mlx_destroy_image(data->mlx, data->textures->img);
		data->textures++;
	}
	return (TRUE);
}

void	free_file(t_data *data)
{
	if (data->line)
	{
		while (get_next_line(data->fd,
				&data->line));
		free(data->line);
	}
	if (data->fd)
		close(data->fd);
}

int	free_all(t_data *data)
{
	free_file(data);
	printf("free all\n");
	free_textures(data);
	ft_freetab(data->map);
	return (TRUE);
}

int	close_mlx(t_data *data, int error)
{
	free_all(data);
	if (data->rays)
		free(data->rays);
	if (data->renderer.img)
		mlx_destroy_image(data->mlx, data->renderer.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(error);
}
