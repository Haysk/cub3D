/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:30:54 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/12 17:51:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include "../libft/libft.h"

size_t	ft_tablen(char **tab);
size_t	ft_intlen(int nbr);

int		ft_findchar(char *str, char c);
char	**my_split(char const *str, char *cutter);

char	*ft_strjoin_gnl(char *s1, char *s2);
int		get_next_line(int fd, char **line);

int		check_file_extension(char *path, char *str);
size_t	whitespace_size(const char *str);
int	empty_line(char *str);

#endif
