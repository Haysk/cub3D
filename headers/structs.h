/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/12 17:56:00 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_resolution
{
	char	*name;
	int		width;	// largeur
	int		height;	// hauteur
	int		(*set)(char **tab, struct s_resolution *res);
}				t_resolution;

typedef struct s_texture
{
	char	*name;
	char	*path;
	int		fd;
	int		(*set)(char **tab, struct s_texture *texture);
}				t_texture;

typedef struct s_color
{
	char	*name;
	int		red;
	int		green;
	int		blue;
	int		(*set)(char **tab, struct s_color *color);
}				t_color;

typedef struct s_params
{
	int				fd;
	t_resolution	*res;
	t_color			*colors;
	t_texture		*textures;
}				t_params;

typedef struct s_tab_funptr
{
	char	*name;
	int		(*set)(char **tab, t_params *params);
}				t_tab_funptr;

#endif
