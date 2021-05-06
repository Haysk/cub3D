/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/06 22:43:58 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "utils.h"
# include "structs.h"

int				open_file(char	*path, char	*extension);

t_params		new_params(void);
t_texture		*init_textures(void);
t_color			*init_colors(void);
t_resolution	set_res(char *line, t_resolution res);
t_resolution	parse_res(char *line, t_resolution res);
t_texture		*set_textures(char *line, t_texture *textures);
t_color			*set_colors(char *line, t_color *colors);
t_params		set_params(char *line, t_params params);
int				print_params(t_params params);

#endif
