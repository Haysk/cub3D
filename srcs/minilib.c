/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:06:34 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 05:10:13 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	slow_loop(void)
{
	double	i;

	i = 0;
	while (i < SKIP_FRAME)
		i++;
}

int	game_loop(t_data *data)
{
	// game_update(data);
	game_render(data);
	return (TRUE);
}
