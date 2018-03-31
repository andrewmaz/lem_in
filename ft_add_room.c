/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:42:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/28 15:15:22 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_add_room(t_room *room)
{
	int		i;
	t_room	*head;

	i = 0;
	if (!room)
	{
		room = ft_new_room();
		return (room);
	}
	head = room;
	while (room->next)
	{
		i++;
		room = room->next;
	}
	room->next = ft_new_room();
	room->next->ind = ++i;
	return (head);
}
