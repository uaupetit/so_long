/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:01:40 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/22 12:19:02 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "../mlx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MLX_ERROR 1
# define SUCCESS 0
# define FAILURE 1
# define IMG_SIZE 64

typedef struct map
{
	int		count_c;
	int		count_p;
	int		count_e;
	int		e_j;
	int		e_i;
	char	*path;
	char	**map;
	int		nb_column;
	int		nb_lines;
	int		fd;
	int		can_exit;
	int		collected;
}			t_map;

typedef struct test
{
	char	**map;
}			t_test;

typedef struct img
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*exit;
	int		height;
	int		width;
	void	*floor;
	void	*player;
	void	*collectible;
}			t_img;

typedef struct data
{
	void	*mlx;
	void	*win;
	int		exit;
	int		j;
	int		i;
	int		p_i;
	int		p_j;
	int		win_height;
	int		win_width;
	int		steps_count;
	int		c_collectible;
	t_img	img;
	t_map	map;
	t_test	test;
}			t_data;

void		destroy(t_data *data);
void		loop(t_data *data);
void		init_map(t_data *data);
t_img		init_img(t_img *img, t_data *data);
int			render(t_data *data);
void		char_to_img(t_data *data, int j, int i, int width);
void		init_images(t_data *data);
int			prefloodfill(char **map, int row, int col);
void		count_chars(t_data *data);
int			edge(t_data *data);
int			is_it_rectangular(t_data *data);
int			count_lines(char *str, t_data *data);
int			ft_strlen(char *str);
int			exit_hook(t_data *data);
void		is_ber(char *str);
void		img(t_data *data);
void		check_counts(t_data *data);
void		find_counts(t_data *data);
int			get_map(t_data *data, char *line);
void		check_chars(t_data *data);
void		parsing(char *str, t_data *data);
int			main(int ac, char **av);
void		init_window(t_data *data);
void		coins_collected(t_data *data, char direction);
void		loop_images(t_data *data);
int			check_next_tile(t_data *data, char direction, char tile);
char		*ft_strchr(const char *s, int c);
int			handle_keypress(int keysym, t_data *data);
void		init_player(t_data *data);
void		move_player(t_data *data, char direction);
int			win_game(t_data *data, char direction);
int			is_map_valid(t_data *data);
int			handle_btnrealease(t_data *data);
int			can_exit(t_data *data, char direction);
int			check_next_img(t_data *data, char direction, char img);
char		**copy_map(t_data *data, int i, int j);
int			is_map_valid(t_data *data);
int			flood_fill(char **map, int row, int col, t_data *data);
void		ft_free(char **tab);
void		ft_free2(t_data *data);
void		chars_checking(t_data *data, char *line);
void		ft_exit(t_data *data, int i, int j);
#endif