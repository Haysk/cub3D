/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:04:15 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/12 18:23:57 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

size_t	whitespace_size(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (ft_strchr(WHITESPACES, str[i]))
		i++;
	return (i);
}

int	empty_line(char *str)
{
	if (!str || !*str)
		return (TRUE);
	if (whitespace_size(str) == ft_strlen(str))
		return (TRUE);
	return (FALSE);
}
