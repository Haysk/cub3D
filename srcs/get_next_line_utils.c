/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:35:20 by adylewsk          #+#    #+#             */
/*   Updated: 2020/02/05 18:44:08 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str && str[i])
		i++;
	return (i);
}

int		ft_findchar(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (str = malloc(sizeof(char)));
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
		return (str);
	*str = 0;
	if (ft_strlen(s) < start)
		return (str);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
