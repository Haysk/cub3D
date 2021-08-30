/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:11:13 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/30 00:16:46 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	key_press(int key, t_data *data)
{
	if (key == 65307)
		close_mlx(data, EXIT_SUCCESS);
	if (key == UP)
		data->player.walk_direction = 1;
	if (key == DOWN)
		data->player.walk_direction = -1;
	if (key == RIGHT)
		data->player.turn_direction = 1;
	if (key == LEFT)
		data->player.turn_direction = -1;
	return (TRUE);
}

int	key_release(int key, t_data *data)
{
	if (key == UP)
		data->player.walk_direction = 0;
	if (key == DOWN)
		data->player.walk_direction = 0;
	if (key == RIGHT)
		data->player.turn_direction = 0;
	if (key == LEFT)
		data->player.turn_direction = 0;
	return (TRUE);
}
