/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/07 00:50:32 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_resolution
{
	int	width;	// largeur
	int	height;	// hauteur
}				t_resolution;

typedef struct s_texture
{
	char	*name;
	char	*path;
	int		fd;
}				t_texture;

typedef struct s_color
{
	char	*name;
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_params
{
	int				fd;
	t_resolution	res;
	t_color			*colors;
	t_texture	*textures;
}				t_params;

#endif
