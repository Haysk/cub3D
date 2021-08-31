/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:13:48 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/31 19:16:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	new_player(t_player *player)
{
	player->x = player->x * TILE_SIZE + (TILE_SIZE / 2);
	player->y = player->y * TILE_SIZE + (TILE_SIZE / 2);
	player->width = 1;
	player->height = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	if ((char)player->rotation_angle == 'E')
		player->rotation_angle = 0;
	if ((char)player->rotation_angle == 'S')
		player->rotation_angle = 1;
	if ((char)player->rotation_angle == 'W')
		player->rotation_angle = 2;
	if ((char)player->rotation_angle == 'N')
		player->rotation_angle = 3;
	player->rotation_angle *= PI / 2;
	player->walk_speed = 5;
	player->turn_speed = 2 * (PI / 180);
}

t_rect	my_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

t_line	my_line(int xa, int ya, int xb, int yb)
{
	t_line	line;

	line.xa = xa;
	line.ya = ya;
	line.xb = xb;
	line.yb = yb;
	line.dx = ft_abs(line.xb - line.xa);
	line.dy = ft_abs(line.yb - line.ya);
	line.sx = -1;
	if (line.xa < line.xb)
		line.sx = 1;
	line.sy = -1;
	if (line.ya < line.yb)
		line.sy = 1;
	line.err = -line.dy / 2;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	line.e2 = 0;
	return (line);
}

int	textures(t_data *data, t_texture *textures)
{
	int	i;

	i = 0;
	while (textures[i].name)
	{
		textures[i].img = mlx_xpm_file_to_image(data->mlx, textures[i].path,
				&textures[i].width, &textures[i].height);
		if (!textures[i].img)
		{
			ft_printf("ERROR\n texture : not found\n");
			return (FALSE);
		}
		if (textures[i].width != TILE_SIZE)
		{
			ft_printf("ERROR\n texture : width 64p / height 64p\n");
			return (FALSE);
		}
		textures[i].addr = (int *)mlx_get_data_addr(textures[i].img,
				&textures[i].bits_per_pixel, &textures[i].line_length,
				&textures[i].endian);
		i++;
	}
	return (TRUE);
}

void	game_setup(t_data *data)
{
	data->win_width = 1920;
	data->win_height = 1080;
	data->scale = 0.25;
	data->fov = 60 * (PI / 180);
	data->renderer.img = NULL;
	data->rays_num = data->win_width;
	data->rays = ft_calloc(data->rays_num + 1, sizeof(t_ray));
	data->mlx = NULL;
	data->win = NULL;
	data->mlx = mlx_init();
	if (!textures(data, data->textures))
		close_mlx(data, EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	new_player(&data->player);
}
