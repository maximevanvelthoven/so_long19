/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:41:47 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 14:53:00 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		file;
	char	*map_line;
	char	**map;
	int		map_row;
	int		map_column;
	int		player;
	int		exit;
	int		collectible;
	int		x;
	int		y;
	void	*connex;
	void	*win;
	void	*wall;
	void	*playerlvl;
	void	*floor;
	void	*exitlvl;
	void	*collec[3];
	int		posx;
	int		posy;
	int		move;
	int		random;
	int		c;
	int		e;

}			t_data;
int			ft_check_valid(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_get_line_map(char *str, t_data *d);
void		check_map(t_data *d);
void		display_map(t_data *d, int i, int j);
void		key_bind(t_data *d);
void		close_window(t_data *d, char *str);
void		ft_free_map(char **str);
void		ft_quit(t_data *d, char *str, int i);
void		get_image(t_data *d);
int			exit_game(t_data *d);
void		back_track_map(t_data *d);

#endif