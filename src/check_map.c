/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:55:37 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 14:45:16 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_up(t_data *d, int j)
{
	d->player = 1;
	d->collectible = 0;
	d->exit = 1;
	while (d->map[0][j])
	{
		if (d->map[0][j] != '1')
			ft_quit(d, "Wall??\n", 0);
		j++;
	}
	if (j != d->map_column)
		ft_quit(d, "invalid size map !\n", 0);
}

void	check_down(t_data *d, int j)
{
	while (d->map[d->map_row][j])
	{
		if (d->map[d->map_row][j] != '1')
			ft_quit(d, "Wall??\n", 0);
		j++;
	}
}

void	check_mid(t_data *d, int i, int j)
{
	while (d->map[i][j])
	{
		if ((int)ft_strlen(d->map[i]) != d->map_column)
			ft_quit(d, "invalid size map !\n", 0);
		if ((j == 0 || j == d->map_column - 1) && d->map[i][j] != '1')
			ft_quit(d, "Wall??\n", 0);
		if (d->map[i][j] != '1' && d->map[i][j] != 'P' && d->map[i][j] != 'E'
			&& d->map[i][j] != 'C' && d->map[i][j] != '0')
			ft_quit(d, "invalid caracter in map.ber\n", 0);
		if (d->map[i][j] == 'E')
			d->exit--;
		if (d->map[i][j] == 'P')
		{
			d->player--;
			d->x = i;
			d->y = j;
		}
		if (d->map[i][j] == 'C')
			d->collectible++;
		j++;
	}
}

void	check_map(t_data *d)
{
	int	i;

	i = 1;
	check_up(d, 0);
	while (i < d->map_row)
	{
		check_mid(d, i, 0);
		i++;
	}
	if (d->player < 0 || d->player > 0)
		ft_quit(d, "invalid number of player only 1 !\n", 0);
	if (d->collectible == 0)
		ft_quit(d, "need at least one collectible !\n", 0);
	if (d->exit < 0 || d->exit > 0)
		ft_quit(d, "invalid number of exit only 1 !\n", 0);
	check_down(d, 0);
}
