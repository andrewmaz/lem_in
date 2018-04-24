/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:08:44 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:26:14 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void ft_copy_lst(t_room *new, t_room *old)
{
	new->name = ft_strdup(old->name);
	new->ind = old->ind;
	new->st_en = old->st_en;
}

void ft_create_road(t_road *road, t_room *room)
{
	t_room *head;
	int i;

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