/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:24:56 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:03:00 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

int	count_lines(char *str, t_data *data)
{
	int		nb_lines;
	int		fd;
	char	*line;

	nb_lines = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	data->map.nb_column = ft_strlen(line);
	while (line != NULL)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	if (nb_lines == 0)
		return (-1);
	return (nb_lines);
}

void	is_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (ft_strlen(str) == -1)
	{
		ft_printf("error : file does not exist\n");
		exit (0);
	}
	if (i > 4)
	{
		if ((str[i - 1] == 'r') && (str[i - 2] == 'e') && (str[i - 3] == 'b')
			&& (str[i - 4] == '.'))
			return ;
		else
		{
			ft_printf("error : wrong file extension\n");
			exit(1);
		}
	}
}

int	get_map(t_data *data, char *line)
{
	int		i;
	int		column;
	int		nb_lines;

	nb_lines = 0;
	while (line != NULL)
	{
		i = 0;
		column = 0;
		data->map.map[nb_lines] = malloc((ft_strlen(line) + 1)
				* sizeof(char *));
		if (!(data->map.map[nb_lines]))
		{
			free(line);
			return (1);
		}
		while (line[i])
			data->map.map[nb_lines][column++] = line[i++];
		data->map.map[nb_lines++][column] = '\0';
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[nb_lines] = NULL;
	return (0);
}

void	parsing(char *str, t_data *data)
{
	char	*line;

	data->map.fd = open(str, O_RDONLY);
	if (data->map.fd == -1)
	{
		ft_printf("error : file does not exist\n");
		exit (1);
	}
	data->map.nb_lines = count_lines(str, data);
	if (data->map.nb_lines == -1)
	{
		ft_printf("error : wrong file content\n");
		exit (1);
	}
	data->map.map = malloc((data->map.nb_lines + 1) * sizeof(char *));
	if (!data->map.map)
	{
		ft_printf("error : invalid file content\n");
		exit (1);
	}
	line = get_next_line(data->map.fd);
	chars_checking(data, line);
}

void	chars_checking(t_data *data, char *line)
{
	if (get_map(data, line) == 1)
	{
		ft_free(data->map.map);
		exit(1);
	}
	close(data->map.fd);
	init_map(data);
	is_it_rectangular(data);
	check_chars(data);
	count_chars(data);
	if (edge(data) == 1)
	{
		ft_printf("error : map not surrounded by walls\n");
		ft_free(data->map.map);
		exit(1);
	}
}
