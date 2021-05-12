/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:35:25 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/10 16:27:55 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	ft_firstline(char **save, char **line)
{
	size_t	i;
	int		end;
	char	*tmp;

	i = 0;
	end = ft_findchar(*save, '\n');
	if (**save == 0)
	{
		*line = malloc(sizeof(char));
		**line = 0;
		return (0);
	}
	while (*(*save + i) && *(*save + i) != '\n')
		i++;
	*line = ft_substr(*save, 0, i);
	tmp = ft_substr(*save, i + 1, ft_strlen(*save) - i - 1);
	free(*save);
	*save = tmp;
	return (end);
}

int	ft_readfile(int fd, char **save)
{
	char	*buffer;
	ssize_t	i;

	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	*buffer = 0;
	while (i > 0 && !ft_findchar(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[i] = 0;
		*save = ft_strjoin_gnl(*save, buffer);
	}
	free(buffer);
	if (i > 0)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save = NULL;
	int			end;

	end = 0;
	*line = NULL;
	if (save && ft_findchar(save, '\n'))
	{
		ft_firstline(&save, line);
		return (1);
	}
	end = ft_readfile(fd, &save);
	if (end == -1)
	{
		*line = malloc(sizeof(char));
		**line = 0;
		return (-1);
	}
	ft_firstline(&save, line);
	if (end == 0)
	{
		free(save);
		save = 0;
	}
	return (end);
}
