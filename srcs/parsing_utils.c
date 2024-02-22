/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:19:25 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void	ft_free2(t_data *data)
{
	if (data->img.wall)
		free(data->img.wall);
	if (data->img.exit)
		free(data->img.exit);
	if (data->img.floor)
		free(data->img.floor);
	if (data->img.collectible)
		free(data->img.collectible);
	if (data->img.player)
		free(data->img.player);
}
