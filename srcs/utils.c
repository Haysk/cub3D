/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:04:15 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/06 23:18:14 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

BOOL	is_whitespace(char character)
{
	char	*whitespaces;

	whitespaces = " \t\r\n\v\f";
	while (*whitespaces)
	{
		if (character == *whitespaces)
			return (TRUE);
		whitespaces++;
	}
	return (FALSE);
}

size_t	whitespace_size(const char *str)
{
	size_t	i;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	return (i);
}

size_t	intlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
