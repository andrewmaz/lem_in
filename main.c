/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/04 17:54:57 by jdoeurok         ###   ########.fr       */
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

int 	ft_min(int a, int b)
{
	if (a < 0)
		return (b);
	else if (b < 0)
		return (a);
	else if (a < b)
		return (a);
	else
		return (b);
}

void	ft_len(int s, int **nmap, int **map, size_t size)
{

	int i;
	int j;

	i = s;
	j = 0;
	while (j < size)
	{
		if (map[i][j])
		{
			nmap[j][j] = ft_min(nmap[s][s] + 1, nmap[j][j]);
		}
		j++;
	}
}

int		ft_cheack(int **nmap, int **map, int i, size_t n)
{
	int r;
	int j;

	r = 0;
	j = 0;
	while (j < n)
	{
		if (map[i][j] && nmap[i][i] == nmap[j][j] + 1)
			r++;
		j++;
	}
	return (r);
}

t_road	*ft_search_road(int e, int **nmap, int **map, size_t n)
{
	t_road *road;
	int i;
	int j;

	i = e;
	j = 0;
	road = ft_new_road();
	road->ind = ft_intrealloc(road->ind, road->len);
	road->ind[road->len++] = e;
	while (nmap[i][j] != 0 && j < n)
	{
		if (map[i][j] && nmap[i][i] == nmap[j][j] + 1)
		{
			road->ind = ft_intrealloc(road->ind, road->len);
			road->ind[road->len++] = j;
			i = j;
			j = 0;
		}
		else
			j++;
	}
	for (int k = road->len - 1; k >= 0; --k)
	{
		ft_printf("%d\n", road->ind[k]);
	}
	return (road);
}

t_road *ft_algor(int s, int e, int **map, size_t n)
{
	int **nmap;
	int i;
	int j;

	nmap = ft_new_map(n, -1);
	i = s;
	nmap[s][s] = 0;
	ft_len(s, nmap, map, n);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j] == 1)
				ft_len(j, nmap, map, n);
			j++;
		}
		i++;
	}
	ft_printf("\n");
	for (int z = 0; z < n; ++z)
	{
		for (int x = 0; x < n; ++x)
		{
			ft_printf("%d ", nmap[z][x]);
		}
		ft_printf("\n");
	}
	return (ft_search_road(e, nmap, map, n));
}

int		main(int argc, char *argv[])
{
	size_t	ants;
	t_room	*room;
	int 	**map;
	char	*input;
	size_t	c_rooms;

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
	ft_algor(s, e, map, c_rooms);
	ft_del_all(room, map, c_rooms, input);
	//system("leaks lem_in_f");
	return (0);
}