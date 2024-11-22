/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:28:33 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 14:51:27 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_mapdup(t_data *d, int i)
{
	char	**mapdup;

	mapdup = malloc(sizeof(char *) * (d->map_row + 2));
	if (!mapdup)
		ft_quit(d, "erreur lors de l initialisation du malloc de backtracking",
			0);
	while (i <= d->map_row)
	{
		mapdup[i] = ft_strdup(d->map[i]);
		i++;
	}
	mapdup[i] = NULL;
	return (mapdup);
}

int	backtrack(char **map, int y, int x, t_data *d)
{
	if (x < 0 || y >= d->map_column || y < 0 || x >= d->map_row)
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'V')
		return (0);
	if (map[x][y] == 'C')
		d->c--;
	if (map[x][y] == 'E')
		d->e--;
	map[x][y] = 'V';
	backtrack(map, y, x + 1, d);
	backtrack(map, y, x - 1, d);
	backtrack(map, y + 1, x, d);
	backtrack(map, y - 1, x, d);
	return (0);
}

void	back_track_map(t_data *d)
{
	char	**mapdup;
	int		x;
	int		y;

	x = d->x;
	y = d->y;
	mapdup = fill_mapdup(d, 0);
	d->e = 1;
	d->c = d->collectible;
	backtrack(mapdup, y, x, d);
	if (d->e != 0 || d->c != 0)
	{
		ft_free_map(mapdup);
		ft_quit(d, "pas de chemin possible sur la map\n", 0);
	}
	ft_free_map(mapdup);
}
