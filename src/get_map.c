/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:48:59 by mvan-vel          #+#    #+#             */
/*   Updated: 2024/08/10 14:51:41 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	checksplit(t_data *d, int fd)
{
	int	i;

	i = 0;
	while (d->map[i])
		i++;
	if (i < d->map_row + 1)
	{
		free(d->map_line);
		close(fd);
		ft_quit(d, "une ligne vide petit coquin !!\n", 1);
	}
}

void	before_split(int fd, t_data *d)
{
	char	*tmp;
	char	*tmp2;

	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmp2 = d->map_line;
		d->map_line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		d->map_row++;
		d->map_column = ft_strlen(tmp);
		free(tmp);
	}
	d->map = ft_split(d->map_line, '\n');
	checksplit(d, fd);
	free(d->map_line);
	free(tmp);
	close(fd);
}

void	ft_get_line_map(char *str, t_data *d)
{
	int	fd;

	d->map_line = ft_strdup("");
	d->map_row = -1;
	fd = open(str, 'r');
	if (fd < 0)
	{
		free(d->map_line);
		ft_quit(d, "error with the file opening\n", 1);
	}
	before_split(fd, d);
}

int	ft_check_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) < 5)
		return (0);
	while (*str && *str != '.')
		str++;
	if (ft_strcmp(str, ".ber") == 0)
		return (1);
	return (0);
}
