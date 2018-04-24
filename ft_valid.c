/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:47:37 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 16:59:24 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



int 	ft_valid_nmap(int s, int e, int **map, size_t n)
{
	size_t j;
	int vs;
	int ve;

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
	if (!ft_valid_nmap(ft_search_st_en(room, 0), ft_search_st_en(room, 1), map, ant_room_fd[1]))
	{
		ft_noroad_err(room, map, ant_room_fd[1], input);
		exit(1);
	}
	ft_putstr(input);
}