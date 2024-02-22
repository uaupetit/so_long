/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:13:01 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 14:41:05 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_data *data)
{
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor2.xpm",
			&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit2.xpm",
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall2.xpm",
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "./textures/perso2.xpm",
			&data->img.width, &data->img.height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collect2.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.player || !data->img.floor
		|| !data->img.collectible || !data->img.exit
		|| !data->img.wall)
	{
		ft_free(data->map.map);
		destroy(data);
	}
}

void	char_to_img(t_data *data, int j, int i, int width)
{
	if (data->map.map[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, width,
			j * 84);
	else if (data->map.map[j][i] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, width,
			j * 84);
	else if (data->map.map[j][i] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, width,
			j * 84);
	else if (data->map.map[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, width,
			j * 84);
	else if (data->map.map[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collectible,
			width, j * 84);
}

int	render(t_data *data)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	j = 0;
	width = 0;
	ft_printf("steps count = %d\r", data->steps_count);
	while (data->map.map[j])
	{
		while (data->map.map[j][i] && data->map.map[j][i] != '\n')
		{
			char_to_img(data, j, i, width);
			width += 84;
			i++;
		}
		i = 0;
		width = 0;
		j++;
	}
	return (1);
}
