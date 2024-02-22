/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:41:35 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_free(data->map.map);
		exit (1);
	}
	data->win = mlx_new_window(data->mlx, data->map.nb_column * 84,
			data->map.nb_lines * 84, "so_long");
	if (data->win == NULL)
	{
		free(data->mlx);
		free(data->win);
		ft_free(data->map.map);
		exit (1);
	}
}

void	loop(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	mlx_loop(data->mlx);
}

int	handle_btnrealease(t_data *data)
{
	ft_free(data->map.map);
	destroy(data);
	return (0);
}

int	exit_hook(t_data *data)
{
	ft_free(data->map.map);
	destroy(data);
	return (0);
}

void	destroy(t_data *data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.collectible)
		mlx_destroy_image(data->mlx, data->img.collectible);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->steps_count == 0)
		ft_printf("steps count = %d\n", data->steps_count);
	else if (data->steps_count > 0)
		ft_printf("steps count = %d\n", data->steps_count - 1);
	free(data->mlx);
	exit(1);
}
