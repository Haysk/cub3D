/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 02:11:13 by adylewsk          #+#    #+#             */
/*   Updated: 2021/08/26 02:11:22 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	game_input(int key, t_data *data)
{
	ft_printf("key : %i\n", key);
	if (key == 65307)
		close_mlx(data);
	return (TRUE);
}
