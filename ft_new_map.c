/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:39:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/28 15:15:22 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



t_room		*ft_new_room(void)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name_room = NULL;
	room->ant = 0;
	room->ind = 0;
	room->st_en = -1;
	room->x = 0;
	room->y = 0;
	room->next = NULL;
	return (room);
}
