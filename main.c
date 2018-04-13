/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/13 17:51:39 by jdoeurok         ###   ########.fr       */
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
			nmap[j][j] = ft_max(nmap[j][j], 0.9 * nmap[e][e]);
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
			{
				nmap[i][j] = nmap[j][j];
			}
			j++;
		}
		i++;
	}
	j = -1;
	while (++j < n)
		nmap[j][j] = 0.0;
	return (nmap);
}

int		ft_max_ind(int i, double **map, size_t n)
{
	int j;
	int ind;

	j = 0;
	ind = 0;
	while (j < n)
	{
		if (map[i][ind] < map[i][j])
			ind = j;
		j++;
	}
	return (ind);
}

int 	ft_goto(int *out, int dest, t_room *room, double **map, size_t n)
{
	t_room *head;

	head = room;
	while (room->ind != dest)
		room = room->next;
	while (head && head->ind != *out)
		head = head->next;
	if (head->st_en == 1)
		return (-1);
	if (room->ant == 0 || room->st_en == 1)
	{
		if (room->st_en != 1)
		{
			map[room->ind][head->ind] *= 0.8;
			map[head->ind][room->ind] *= 0.8;
		}
		room->ant++;
		head->ant--;
		*out = room->ind;
		return (room->ind);
	}
	return (-1);
}

size_t	ants_in_end(t_room *room)
{
	while (room && room->st_en != 1)
		room = room->next;
	return (room->ant);
}

t_road	*ft_road(size_t ants, t_room *room, double **map, size_t n)
{
	int s_e[2];
	int i;
	int j;
	t_road *road;
	t_road *head;

	road = ft_new_road();
	road->ant_num = 1;
	head = road;
	s_e[0] = ft_search_st_en(room, 0);
	s_e[1] = ft_search_st_en(room, 1);
	int dest;
	int go;
	while (ants_in_end(room) != ants)
	{
		dest = ft_max_ind(s_e[0], map, n);
		go = ft_goto(&s_e[0], dest, room, map, n);
		if (go == -1)
		{
			s_e[0] = ft_search_st_en(room, 0);
			road->next = ft_new_road();
			road->next->ant_num = road->ant_num + 1;
			road = road->next;
		}
		else
		{
			road->ind = ft_intrealloc(road->ind, road->len);
			road->ind[road->len++] = go;
		}
	}
	return (head);
}

void	ft_set_ants2st(t_room *room, size_t ants)
{
	while (room && room->st_en != 0)
		room = room->next;
	if (room)
		room->ant = ants;
}

int		ft_valid_nmap(int s, int e, double **map, size_t n)
{
	int i;
	int j;
	int vs;
	int ve;

	vs = 0;
	ve = 0;
	i = s;
	j = 0;
	while (j < n)
	{
		if (map[i][j] > 0.0)
			vs = 1;
		j++;
	}
	i = e;
	j = 0;
	while (j < n)
	{
		if (map[i][j] > 0.0)
			ve = 1;
		j++;
	}
	return (vs && ve);
}

void	ft_output(int i, int j, t_road *road, t_room *room)
{
	char *res;

	res = NULL;

	res = ft_realcat(res, "\n");
	ft_putchar('\n');
	while (i < road->len)
	{
		res = ft_realcat(res, "L");
		res = ft_realcat(res, ft_itoa(road->ant_num)); ///leak
		res = ft_realcat(res, "-");
		res = ft_realcat(res, ft_search_name(road->ind[i], room));
		res = ft_realcat(res, "\n");
		i++;
	}
	ft_putstr(res);
}

int		main(int argc, char *argv[])
{
	size_t	ants;
	t_room	*room;
	int 	**map;
	char	*input;
	size_t	c_rooms;
	double	**nmap;
	t_road	*road;

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
	int s = ft_search_st_en(room, 0);
	int e = ft_search_st_en(room, 1);
	ft_set_ants2st(room, ants);
	nmap = ft_algor(s, e, map, c_rooms);
	if (!ft_valid_nmap(s, e, nmap, c_rooms))
	{
		ft_st_en_err(room, map, c_rooms, input);
		ft_del_map(nmap, c_rooms);
		system("leaks lem_in_f");
		exit(1);
	}
	ft_putstr(input);
	road = ft_road(ants, room, nmap, c_rooms);
	ft_output(0, 0, road, room);
	ft_printf("\n");
	while (road)
	{
		for (int i = 0; i < road->len; ++i)
		{
			ft_printf("%d ", road->ind[i]);
		}
		road = road->next;
		ft_printf("\n");
	}
	ft_del_all(room, map, c_rooms, input);
	ft_del_map(nmap, c_rooms);
	//system("leaks lem_in_f");
	return (0);
}