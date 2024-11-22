/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:37:31 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/09 22:04:13 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *d)
{
	close_window(d, "you quit the game come back !\n");
	return (0);
}

void	execute_key(t_data *d, int flag)
{
	d->random += 1;
	if (flag == 0)
	{
		mlx_clear_window(d->connex, d->win);
		d->y += 1;
		display_map(d, 0, 0);
	}
	if (flag == 1)
	{
		mlx_clear_window(d->connex, d->win);
		d->y -= 1;
		display_map(d, 0, 0);
	}
	if (flag == 2)
	{
		mlx_clear_window(d->connex, d->win);
		d->x += 1;
		display_map(d, 0, 0);
	}
	if (flag == 3)
	{
		mlx_clear_window(d->connex, d->win);
		d->x -= 1;
		display_map(d, 0, 0);
	}
}

void	prepare_to_execute(t_data *d, int flag)
{
	if (flag == 0)
	{
		execute_key(d, flag);
		d->move += 1;
	}
	if (flag == 1)
	{
		execute_key(d, flag);
		d->move += 1;
	}
	if (flag == 2)
	{
		execute_key(d, flag);
		d->move += 1;
	}
	if (flag == 3)
	{
		execute_key(d, flag);
		d->move += 1;
	}
}

int	handle_key(int keycode, t_data *d)
{
	if (keycode == 2 && d->map[d->x][d->y + 1] != '1')
		prepare_to_execute(d, 0);
	if (keycode == 0 && d->map[d->x][d->y - 1] != '1')
		prepare_to_execute(d, 1);
	if (keycode == 1 && d->map[d->x + 1][d->y] != '1')
		prepare_to_execute(d, 2);
	if (keycode == 13 && d->map[d->x - 1][d->y] != '1')
		prepare_to_execute(d, 3);
	ft_printf("nombre de move : %d\n", d->move);
	if (keycode == 53)
		exit_game(d);
	return (0);
}

void	key_bind(t_data *d)
{
	d->move = 0;
	mlx_key_hook(d->win, handle_key, d);
}
