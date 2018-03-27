/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:39:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/27 15:44:52 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



t_room		*ft_new_room(void)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->ant = 0;
	room->st_en = -1;
	room->x = 0;
	room->y = 0;
	return (room);
}
