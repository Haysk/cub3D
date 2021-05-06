/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/05/07 00:55:34 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	start(char *file)
{
	char		*line;
	t_params	params;

	line = NULL;
	params = new_params();
	params.fd = open_file(file, ".cub");
	while (get_next_line(params.fd, &line))
	{
		// printf("%s\n", line);
		params = set_params(line, params);
		free(line);
	}
	print_params(params);
	free(line);
	close(params.fd);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	errno = 0;
	if (argc > 1 && argc < 4)
	{
		if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		{
			printf("ERROR\nArgument : cub3D filename.cub [--save]");
			return (EXIT_FAILURE);
		}
		return (start(argv[1]));
	}
	printf("ERROR\nArgument : cub3D filename.cub [--save]");
	return (EXIT_FAILURE);
}
