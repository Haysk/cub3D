/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:40:56 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/11 21:47:27 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

static	int	ft_nbr_word(char *str, char *cutter)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (!ft_strchr(cutter, str[i])
			&& (ft_strchr(cutter, str[i + 1]) || !str[i + 1]))
			nb_word++;
		i++;
	}
	return (nb_word);
}

static	int	ft_len_word(char *str, char *cutter)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(cutter, str[i]))
		i++;
	return (i);
}

static	char	*ft_get_word(char **src, char *cutter)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_len_word(*src, cutter) + 1));
	if (!cpy)
		return (0);
	while (**src && !ft_strchr(cutter, **src))
	{
		cpy[i] = **src;
		*src += 1;
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	**my_split(char const *str, char *cutter)
{
	int		i;
	char	**tab;
	char	*save;

	i = 0;
	save = (char *)str;
	if (!str)
		return (NULL);
	tab = ft_calloc(ft_nbr_word(save, cutter) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (save && *save)
	{
		if (!ft_strchr(cutter, *save))
		{
			tab[i] = ft_get_word(&save, cutter);
			i++;
		}
		else
			save++;
	}
	tab[i] = 0;
	return (tab);
}
