/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:36 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/12 17:55:13 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	free_textures(t_texture *textures)
{
	while (textures->name)
	{
		if (textures->fd)
			close(textures->fd);
		if (textures->path != NULL)
			free(textures->path);
		textures++;
	}
	return (EXIT_SUCCESS);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (EXIT_FAILURE);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (EXIT_SUCCESS);
}

int	free_all(char *line, t_params *params)
{
	printf("free all\n");
	if (params->fd)
		close(params->fd);
	free_textures(params->textures);
	if (line != NULL)
		free(line);
	return (EXIT_SUCCESS);
}
