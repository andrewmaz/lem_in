/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:08:44 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 14:08:24 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_in_last_road(t_road *road)
{
	while (road->next)
		road = road->next;
	return (road->road[0]);
}

void	ft_swap_road(t_road *a, t_road *b)
{
	int		*t;
	t_room	*m;
	int		p;

	t = a->road;
	m = a->room;
	p = a->len;
	a->road = b->road;
	a->room = b->room;
	a->len = b->len;
	b->road = t;
	b->room = m;
	b->len = p;
}

t_road	*ft_sort_road(t_road *road)
{
	t_road *i;
	t_road *j;

	i = road;
	while (i)
	{
		j = road;
		while (j->next)
		{
			if (j->len > j->next->len)
				ft_swap_road(j, j->next);
			j = j->next;
		}
		i = i->next;
	}
	return (road);
}

void	ft_copy_lst(t_room *new, t_room *old)
{
	new->name = ft_strdup(old->name);
	new->ind = old->ind;
	new->st_en = old->st_en;
}

void	ft_create_road(t_road *road, t_room *room)
{
	t_room	*head;
	int		i;

	while (road)
	{
		i = 0;
		head = NULL;
		while (i < road->len && road->ant_num)
		{
			if (!road->room)
			{
				road->room = ft_new_room();
				head = road->room;
			}
			else
			{
				road->room->next = ft_new_room();
				road->room->next->prev = road->room;
				road->room = road->room->next;
			}
			ft_copy_lst(road->room, ft_search_room(road->road[i++], room));
		}
		road->room = head;
		road = road->next;
	}
}
