/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:36:11 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:27:27 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_search_st_en(t_room *room, int s_e)
{
	while (room)
	{
		if (room->st_en == s_e)
			return (room->ind);
		room = room->next;
	}
	return (-1);
}

t_room		*ft_search_room(int ind, t_room *room)
{
	while (room)
	{
		if (room->ind == ind)
			return (room);
		room = room->next;
	}
	return (NULL);
}

static void	ft_help_road(int i, int **map, t_road *road, size_t n)
{
	size_t j;
	size_t k;

	j = 0;
	while (j < n && map[i][j] != 0)
	{
		if (map[i][j] == ft_min_len(i, map, n) && ft_min_len(i, map, n) != -1)
		{
			road->road = ft_intrealloc(road->road, road->len);
			road->road[road->len++] = (int)j;
			k = 0;
			while (k < n)
				map[k++][j] = -1;
			map[i][j] = -1;
			map[j][i] = -1;
			i = (int)j;
			j = 0;
		}
		else
			j++;
	}
}

int			ft_search_ind(char *name, t_room *room)
{
	int i;

	i = -1;
	while (room)
	{
		if (ft_strequ(name, room->name))
			i = room->ind;
		room = room->next;
	}
	return (i);
}

t_road		*ft_search_road(t_road *head, int e, int **map, size_t n)
{
	t_road *road;

	road = head;
	while (road && road->next)
		road = road->next;
	if (!road)
		road = ft_new_road();
	else
	{
		road->next = ft_new_road();
		road->next->prev = road;
		road = road->next;
	}
	road->road = ft_intrealloc(road->road, road->len);
	road->road[road->len++] = e;
	ft_help_road(e, map, road, n);
	road->road = ft_revers(road->road, road->len);
	if (!head)
		head = road;
	return (head);
}
