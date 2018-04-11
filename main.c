/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/11 16:40:53 by jdoeurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int		ft_search_st_en(t_room *room, int s_e)
{
	while (room)
	{
		if (room->st_en == s_e)
			return (room->ind);
		room = room->next;
	}
	return (-1);
}

double 	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_ferom(int e, double **nmap, int **map, size_t n)
{
	int i;
	int j;

	i = e;
	j = 0;
	while (j < n)
	{
		if (map[i][j])
			nmap[j][j] = ft_max(nmap[j][j], 0.8 * nmap[e][e]);
		j++;
	}
}

double **ft_algor(int s, int e, int **map, size_t n)
{
	int i;
	int j;
	double **nmap;

	////
	i = 0;
	nmap = (double**)malloc(sizeof(double*) * n);
	while (i < n)
	{
		j = 0;
		nmap[i] = (double *)malloc(sizeof(double) * n);
		while (j < n)
			nmap[i][j++] = 0.0;
		i++;
	}
	/////

	i = e;
	nmap[e][e] = 1.0;
	ft_ferom(e, nmap, map, n);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j])
				ft_ferom(j, nmap, map, n);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j])
				nmap[i][j] = nmap[j][j];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < n)
		nmap[j][j++] = 0.0;
	return (nmap);
}

void *ft_road(t_room *room, double **nmap, size_t n)
{
	int k[2];

	//!doit
}

int		main(int argc, char *argv[])
{
	size_t	ants;
	t_room	*room;
	int 	**map;
	char	*input;
	size_t	c_rooms;
	double	**nmap;

	input = NULL;
	room = NULL;
	map = NULL;
	///
	int fd = open("../map/big.map", O_RDONLY);
	if (fd < 0)
		perror("Error");
	///
	ants = ft_read_ants(fd, &input);
	ft_read_all(&room, &map, &input, fd);
	c_rooms = ft_room_count(room);
	ft_putstr(input);
	for (int i = 0; i < c_rooms; ++i)
	{
		for (int j = 0; j < c_rooms; ++j)
		{
			ft_printf("%d ", map[i][j]);
		}
		ft_printf("\n");
	}
	int s = ft_search_st_en(room, 0);
	int e = ft_search_st_en(room, 1);
	nmap = ft_algor(s, e, map, c_rooms);
	ft_road(room, nmap, c_rooms);
	ft_printf("\n");
	for (int i = 0; i < c_rooms; ++i)
	{
		for (int j = 0; j < c_rooms; ++j)
		{
			ft_printf("%d ", map[i][j]);
		}
		ft_printf("\n");
	}
	ft_algor(s, e, map, c_rooms);
	ft_del_all(room, map, c_rooms, input);
	//system("leaks lem_in_f");
	return (0);
}