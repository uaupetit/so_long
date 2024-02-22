/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:12:15 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:03:00 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	int			resread;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	resread = 1;
	while (!(ft_strchr2(stash, '\n')) && (resread != 0))
	{
		resread = read(fd, buffer, BUFFER_SIZE);
		if (resread == -1 && !stash)
		{
			free (buffer);
			return (NULL);
		}
		buffer[resread] = '\0';
		stash = ft_strjoin2(stash, buffer);
	}
	free(buffer);
	buffer = ft_line(stash);
	stash = ft_delline(stash, resread);
	return (buffer);
}
/*
int	main()
{
	int	fd;
	int	i;
	char	*res;

	i = 0;
	fd = open("GNL.txt", O_RDONLY);
	while (i <= 5)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	close(fd);
}*/
