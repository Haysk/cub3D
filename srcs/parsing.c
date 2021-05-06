/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:00:46 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/07 01:15:17 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_resolution	parse_res(char *line, t_resolution res)
{
	size_t	whitespaces;

	printf("parse : %s\n", line);
	whitespaces = whitespace_size(line);
	res.width = ft_atoi(line);
	res.height = ft_atoi(line + intlen(res.width) + whitespaces);
	if (res.width < 800 || res.height < 600
		|| res.width > 1920 || res.height > 1080)
	{
		printf("ERROR\nresolution \"%i %i\" : min \"800 600\" max \"1920 1080\"\n",
			res.width, res.height);
		errno = 1;
		//fermer le fichier ouvert
	}
	return (res);
}

// t_texture	parse_texture(char *line, t_texture texture)
// {
// 	char	*save;

// 	save = line + whitespace_size(line);
// }
