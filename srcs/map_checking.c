/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:38 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_it_rectangular(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map.nb_column = ft_strlen(data->map.map[j]) - 1;
	while (data->map.map[j])
	{
		while (data->map.map[j][i] && data->map.map[j][i] != '\n')
			i++;
		if (i != data->map.nb_column)
		{
			ft_printf("error : wrong map form\n");
			ft_free(data->map.map);
			exit(1);
		}
		i = 0;
		j++;
	}
	return (0);
}

int	edge(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map.map[j])
	{
		i = -1;
		while (data->map.map[j][++i] != data->map.map[j][data->map.nb_column])
		{
			if (data->map.map[j][i] != '1')
				return (1);
		}
		if (j == 0 || j != data->map.nb_lines - 1)
			j = data->map.nb_lines - 1;
		else
			j++;
	}
	j = 0;
	while ((++j > 0) && (j < data->map.nb_lines - 1))
	{
		if (data->map.map[j][0] != '1' || data->map.map[j][data->map.nb_column
			- 1] != '1')
			return (1);
	}
	return (0);
}

void	check_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != (data->map.nb_lines - 1))
	{
		while (i != (data->map.nb_column - 1))
		{
			if (data->map.map[j][i] == 'C' || data->map.map[j][i] == 'P'
				|| data->map.map[j][i] == 'E' || data->map.map[j][i] == '1'
				|| data->map.map[j][i] == '0')
				i++;
			else
			{
				ft_printf("error : invalid characters in map\n");
				ft_free(data->map.map);
				exit(1);
			}
		}
		j++;
		i = 0;
	}
}

void	count_chars(t_data *data)
{
	int	j;
	int	i;

	j = -1;
	while (data->map.map[++j])
	{
		i = -1;
		while (data->map.map[j][++i])
		{
			if (data->map.map[j][i] == 'P')
				data->map.count_p++;
			else if (data->map.map[j][i] == 'C')
				data->map.count_c++;
			else if (data->map.map[j][i] == 'E')
				ft_exit(data, j, i);
		}
	}
	if (!data->map.count_c || !data->map.count_e || !data->map.count_p
		|| data->map.count_e > 1 || data->map.count_p > 1)
	{
		ft_printf("error : too many or few P.E.C characters\n");
		ft_free(data->map.map);
		exit(1);
	}
}

void	ft_exit(t_data *data, int j, int i)
{
	data->map.count_e++;
	data->map.e_j = j;
	data->map.e_i = i;
}
