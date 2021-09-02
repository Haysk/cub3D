/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:11:13 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/01 18:30:25 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	key_press(int key, t_data *data)
{
	if (key == 65307)
		close_mlx(data, EXIT_SUCCESS);
	if (key == UP)
		data->player.walk_direction += 1;
	if (key == DOWN)
		data->player.walk_direction += -1;
	if (key == RIGHT)
		data->player.walk_side_direction += 1;
	if (key == LEFT)
		data->player.walk_side_direction += -1;
	if (key == RIGHT_ARROW)
		data->player.turn_direction += 1;
	if (key == LEFT_ARROW)
		data->player.turn_direction += -1;
	return (TRUE);
}

int	key_release(int key, t_data *data)
{
	if (key == UP)
		data->player.walk_direction += -1;
	if (key == DOWN)
		data->player.walk_direction += 1;
	if (key == RIGHT)
		data->player.walk_side_direction += -1;
	if (key == LEFT)
		data->player.walk_side_direction += 1;
	if (key == RIGHT_ARROW)
		data->player.turn_direction += -1;
	if (key == LEFT_ARROW)
		data->player.turn_direction += 1;
	return (TRUE);
}
