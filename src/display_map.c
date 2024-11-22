/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:25:28 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 14:48:14 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_collec(t_data *d, int i, int j)
{
	if (d->random == 3)
		d->random = 0;
	mlx_put_image_to_window(d->connex, d->win, d->collec[d->random], j * 64, i
		* 64);
	if (d->map[d->x][d->y] == 'C')
	{
		d->collectible--;
		d->map[d->x][d->y] = '0';
		mlx_put_image_to_window(d->connex, d->win, d->floor, d->y * 64, d->x
			* 64);
		if (d->collectible > 0)
			mlx_put_image_to_window(d->connex, d->win, d->playerlvl, d->y * 64,
				d->x * 64);
		else
		{
			mlx_destroy_image(d->connex, d->playerlvl);
			d->playerlvl = mlx_xpm_file_to_image(d->connex,
					"xpmfile/playercool.xpm", &d->posx, &d->posy);
			mlx_put_image_to_window(d->connex, d->win, d->playerlvl, d->y * 64,
				d->x * 64);
		}
	}
}

void	put_to_win(t_data *d, int i, int j)
{
	if (d->map[i][j])
		mlx_put_image_to_window(d->connex, d->win, d->floor, j * 64, i * 64);
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->connex, d->win, d->wall, j * 64, i * 64);
	if (d->map[i][j] == 'E')
	{
		if (d->map[d->x][d->y] == 'E' && d->collectible == 0)
			close_window(d, "BIEN OUEJ");
		else
			mlx_put_image_to_window(d->connex, d->win, d->exitlvl, j * 64, i
				* 64);
	}
	if (d->map[i][j] == 'C')
		handle_collec(d, i, j);
	if (d->map[d->x][d->y])
		mlx_put_image_to_window(d->connex, d->win, d->playerlvl, d->y * 64, d->x
			* 64);
}

void	get_image(t_data *d)
{
	d->posx = 1000;
	d->posy = 1000;
	d->random = 0;
	d->floor = mlx_xpm_file_to_image(d->connex, "xpmfile/floor.xpm", &d->posx,
			&d->posy);
	d->wall = mlx_xpm_file_to_image(d->connex, "xpmfile/wall.xpm", &d->posx,
			&d->posy);
	d->playerlvl = mlx_xpm_file_to_image(d->connex, "xpmfile/player.xpm",
			&d->posx, &d->posy);
	d->exitlvl = mlx_xpm_file_to_image(d->connex, "xpmfile/exit.xpm", &d->posx,
			&d->posy);
	d->collec[0] = mlx_xpm_file_to_image(d->connex, "xpmfile/collectible1.xpm",
			&d->posx, &d->posy);
	d->collec[1] = mlx_xpm_file_to_image(d->connex, "xpmfile/collectible2.xpm",
			&d->posx, &d->posy);
	d->collec[2] = mlx_xpm_file_to_image(d->connex, "xpmfile/collectible3.xpm",
			&d->posx, &d->posy);
	if (!d->floor || !d->wall || !d->playerlvl || !d->exitlvl || !d->collec[0]
		|| !d->collec[1] || !d->collec[2])
		close_window(d, "error with file .xpm\n");
	display_map(d, 0, 0);
}

void	display_map(t_data *d, int i, int j)
{
	while (d->map[i][j] && i < d->map_row)
	{
		while (d->map[i][j] && j < d->map_column)
		{
			put_to_win(d, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	while (d->map[d->map_row][j])
	{
		put_to_win(d, i, j);
		j++;
	}
}
