/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:52:58 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mapscan(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	flood_fill(char **map, int row, int col, t_data *data)
{
	if (map[row][col] == 'E')
		data->exit++;
	if (map[row][col] == '0' || map[row][col] == 'P' || map[row][col] == 'C')
	{
		if (map[row][col] == 'C')
			data->c_collectible++;
		map[row][col] = '+';
		flood_fill(map, row - 1, col, data);
		flood_fill(map, row + 1, col, data);
		flood_fill(map, row, col - 1, data);
		flood_fill(map, row, col + 1, data);
	}
	return (0);
}

int	prefloodfill(char **map, int row, int col)
{
	if (map[row][col] && map[row + 1][col] && map[row - 1][col]
		&& map[row][col + 1] && map[row][col - 1])
	{
		if ((map[row + 1][col] == '1' || map[row + 1][col] == 'E') && (map[row
				- 1][col] == '1' || map[row - 1][col] == 'E') && (map[row][col
				+ 1] == '1' || map[row][col + 1] == 'E') && (map[row][col
				- 1] == '1' || map[row][col - 1] == 'E'))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	is_map_valid(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	j = 0;
	map = copy_map(data, i, j);
	if (prefloodfill(map, data->p_j, data->p_i) == 1)
	{
		ft_printf("error : game is not winable\n");
		ft_free(data->map.map);
		ft_free(map);
		exit(1);
	}
	flood_fill(map, data->p_j, data->p_i, data);
	if (mapscan(map) == 1 || (data->exit < 1))
	{
		ft_printf("error : game is not winable\n");
		ft_free(data->map.map);
		ft_free(map);
		exit(1);
	}
	ft_free(map);
	return (0);
}

char	**copy_map(t_data *data, int i, int j)
{
	char	**copymap;

	copymap = malloc(sizeof(char *) * (data->map.nb_lines + 1));
	if (!copymap)
	{
		ft_free(data->map.map);
		exit(1);
	}
	while (++i < data->map.nb_lines)
	{
		copymap[i] = malloc(sizeof(char) * (data->map.nb_column + 1));
		if (!copymap[i])
		{
			ft_free(data->map.map);
			exit(1);
		}
		j = -1;
		while (++j < data->map.nb_column)
			copymap[i][j] = data->map.map[i][j];
		copymap[i][j] = '\0';
	}
	copymap[i] = NULL;
	return (copymap);
}
