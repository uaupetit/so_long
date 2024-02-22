/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:18 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_data *data)
{
	data->steps_count = 0;
	data->p_i = 0;
	data->p_j = 0;
	data->exit = 0;
	data->c_collectible = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.e_j = 0;
	data->map.e_i = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->win_height = data->map.nb_lines * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map.map[j])
	{
		i = 0;
		while (data->map.map[j][i])
		{
			if (data->map.map[j][i] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	img(t_data *data)
{
		data->img.player = NULL;
		data->img.collectible = NULL;
		data->img.wall = NULL;
		data->img.floor = NULL;
		data->img.exit = NULL;
}
