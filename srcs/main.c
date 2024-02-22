/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:49 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 14:41:09 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		is_ber(av[1]);
		parsing(av[1], &data);
		img(&data);
		init_player(&data);
		is_map_valid(&data);
		init_window(&data);
		init_images(&data);
		render(&data);
		loop(&data);
	}
}
