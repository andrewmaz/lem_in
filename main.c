/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/17 17:15:50 by jdoeurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

void	ft_swap_int(int *a, int *b)
{
	int c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
	else
		return ;
}

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

int		ft_mini(int i, int **map, size_t n)
{
	int j;
	int res;

	j = 0;
	res = map[i][j];
	while (j < n)
	{
		if (map[i][j] != -1)
			res = ft_min(res, map[i][j]);
		j++;
	}
	return (res);
}

int		*ft_revers(int *in, size_t size)
{
	int i;

	i = 0;
	size--;
	while (i < size)
	{
		ft_swap_int(&in[i++], &in[size--]);
	}
	return (in);
}

t_road	*ft_search_road(int e, int **map, size_t n)
{
	t_road *road;
	int i;
	int j;

	i = e;
	j = 0;
	road = ft_new_road();
	road->ind = ft_intrealloc(road->ind, road->len);
	road->ind[road->len++] = e;
	while (map[i][j] != 0 && j < n)
	{
		if (map[i][j] == ft_mini(i, map, n))
		{
			road->ind = ft_intrealloc(road->ind, road->len);
			road->ind[road->len++] = j;
			i = j;
			j = 0;

		}
		else
			j++;
	}
	road->ind = ft_revers(road->ind, road->len);
	return (road);
}

int		ft_valid_nmap(int s, int e, int **map, size_t n)
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
		if (map[i][j] > -1)
			vs = 1;
		j++;
	}
	i = e;
	j = 0;
	while (j < n)
	{
		if (map[i][j] > -1)
			ve = 1;
		j++;
	}
	return (vs && ve);
}

int **ft_algor(int s, int e, int **map, size_t n)
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
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j])
			{
				nmap[i][j] = nmap[j][j];
				//nmap[j][i] = nmap[j][j];
			}
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < n)
		nmap[i][i] = -1;
	ft_del_map(map, n);
	return (nmap);
}

void	ft_set_ants2st(t_room *room, size_t ants)
{
	while (room && room->st_en != 0)
		room = room->next;
	if (room)
		room->ant = ants;
}



void	ft_output(int i, int j, t_road *road, t_room *room)
{
	char *res;
	int a;

	res = NULL;
	a = 1;
	res = ft_realcat(res, "\n");
	ft_putchar('\n');
	while (i < road->len)
	{
		res = ft_realcat(res, "L");
		res = ft_realcat(res, ft_itoa(a)); ///leak
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
	//int	**nmap;
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
	map = ft_algor(s, e, map, c_rooms);
	if (!ft_valid_nmap(s, e, map, c_rooms))
	{
		ft_st_en_err(room, map, c_rooms, input);
		system("leaks lem_in_f");
		exit(1);
	}
	ft_putstr(input);
	ft_printf("\n");
	for (int z = 0; z < c_rooms; ++z)
	{
		for (int x = 0; x < c_rooms; ++x)
		{
			ft_printf("%3d ", map[z][x]);
		}
		ft_printf("\n");
	}
	road = ft_search_road(e, map, c_rooms);
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
	//ft_del_map(nmap, c_rooms);
	//system("leaks lem_in_f");
	return (0);
}