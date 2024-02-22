/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:18 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:01:30 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_j][data->p_i + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_j][data->p_i - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_j + 1][data->p_i] == tile)
		|| (direction == 'w' && data->map.map[data->p_j - 1]
			[data->p_i] == tile))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	coins_collected(t_data *data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_j][data->p_i + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_j][data->p_i - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_j + 1][data->p_i] == 'C')
		|| (direction == 'w' && data->map.map[data->p_j - 1][data->p_i] == 'C'))
		data->map.collected++;
}

void	move_player(t_data *data, char direction)
{
	if ((check_next_tile(data, direction, '1') == SUCCESS)
		|| (data->map.can_exit == 0 && check_next_tile(data, direction,
				'E') == SUCCESS))
		return ;
	coins_collected(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_j][data->p_i] = '0';
	if (direction == 'w')
		data->p_j--;
	else if (direction == 'a')
		data->p_i--;
	else if (direction == 's')
		data->p_j++;
	else if (direction == 'd')
		data->p_i++;
	data->map.map[data->p_j][data->p_i] = 'P';
	render(data);
	if (data->map.map[data->p_j][data->p_i] ==
		data->map.map[data->map.e_j][data->map.e_i] && data->map.can_exit == 1)
	{
		ft_free(data->map.map);
		destroy(data);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_free(data->map.map);
		destroy(data);
	}
	if (ft_strchr("wasd", keysym))
	{
		move_player(data, (char)keysym);
		data->steps_count++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 127)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
