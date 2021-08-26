/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 04:55:24 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include "utils.h"
# include "structs.h"

int			open_file(char *path, char *extension);

int			my_error(int error, char *str);
int			free_tab(char **tab);
int			free_all(t_data *data);

t_data		new_data(int fd);
t_texture	*init_textures(void);
t_color		*init_colors(void);

int			set_colors(char **tab, t_color *colors);
int			set_textures(char **tab, t_texture *texture);
int			set_params(t_data *data);

int			params_is_set(t_data data);
int			print_params(t_data data);

int			get_map(t_data *data);
int			check_map(t_data *data);
int			check_borders(t_data *data);
void		check_params(t_data *data);

void		new_game(t_data *data);
void		my_put_pixel(t_image *renderer, int x, int y, int color);
t_rect		init_rect(int x, int y, int width, int height);
void		put_rect(t_rect rect, t_image *renderer, int color);
int			game_loop(t_data *data);
void		slow_loop();
void		game_setup(t_data *data);
int			game_input(int key, t_data *data);
void		game_update(t_data *data);
void		game_render(t_data *data);
int			close_mlx(t_data *data);





#endif
