/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:31:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 16:37:53 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (FALSE);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (TRUE);
}
