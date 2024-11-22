/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:35:03 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 17:30:11 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_quit(t_data *d, char *str, int i)
{
	if (i == 0)
		ft_free_map(d->map);
	if (str)
		ft_putstr_fd(str, 2);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	close_window(t_data *d, char *str)
{
	if (d->connex)
		mlx_destroy_window(d->connex, d->win);
	if (d->floor != NULL)
		mlx_destroy_image(d->connex, d->floor);
	if (d->wall != NULL)
		mlx_destroy_image(d->connex, d->wall);
	if (d->playerlvl != NULL)
		mlx_destroy_image(d->connex, d->playerlvl);
	if (d->exitlvl != NULL)
		mlx_destroy_image(d->connex, d->exitlvl);
	if (d->collec[0] != NULL)
		mlx_destroy_image(d->connex, d->collec[0]);
	if (d->collec[1] != NULL)
		mlx_destroy_image(d->connex, d->collec[1]);
	if (d->collec[2] != NULL)
		mlx_destroy_image(d->connex, d->collec[2]);
	ft_quit(d, str, 0);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		return (0);
	if (ft_check_valid(av[1]) == 0)
		ft_quit(&d, "incorrect file ! model : tata.ber\n", 1);
	ft_get_line_map(av[1], &d);
	check_map(&d);
	back_track_map(&d);
	d.connex = mlx_init();
	if (!d.connex)
		ft_quit(&d, "error initialisation with the init\n", 0);
	d.win = mlx_new_window(d.connex, d.map_column * TILE_SIZE, (d.map_row + 1)
			* TILE_SIZE, "oui oui");
	if (d.win == NULL)
		ft_quit(&d, "error initialisation with the window\n", 0);
	get_image(&d);
	key_bind(&d);
	mlx_hook(d.win, 17, 1L >> 17, exit_game, &d);
	mlx_loop(d.connex);
	return (0);
}
