/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/09/02 15:15:55 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	get_params(char *file)
{
	t_data	data;
	int		set;

	data = new_data(open_file(file, ".cub"));
	set = TRUE;
	while (!data.params_is_set && set && !data.end_file)
	{
		data.end_file = !get_next_line(data.fd, &data.line);
		if (!empty_line(data.line))
			set = set_params(&data);
		data.params_is_set = params_is_set(data);
	}
	data.map_is_set = get_map(&data);
	check_params(&data);
	start(&data);
	free_all(&data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (get_params(argv[1]));
	return (my_error(1, NULL));
}
