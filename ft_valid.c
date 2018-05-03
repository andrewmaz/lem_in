/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:47:37 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 18:22:41 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_valid_room(char **tmp, t_room *room)
{
	ssize_t x;
	ssize_t y;

	x = ft_atoi(tmp[1]);
	y = ft_atoi(tmp[2]);
	while (room)
	{
		if (room->name && (ft_strequ(tmp[0], room->name) || \
			(x == room->x && y == room->y)))
			return (0);
		room = room->next;
	}
	return (1);
}

int		ft_valid_nmap(int s, int e, int **map, size_t n)
{
	size_t	j;
	int		vs;
	int		ve;

	vs = 0;
	ve = 0;
	j = 0;
	while (j < n)
	{
		if (map[s][j] > -1)
			vs = 1;
		if (map[e][j] > -1)
			ve = 1;
		j++;
	}
	return (vs && ve);
}

void	ft_valid_link(t_room *room, int **map, size_t *ant_room_fd, char *input)
{
	if (!ft_valid_nmap(ft_search_st_en(room, 0), ft_search_st_en(room, 1), \
				map, ant_room_fd[1]))
	{
		ft_input_err(room, map, input, "No road");
		ft_exit(NULL);
	}
}
