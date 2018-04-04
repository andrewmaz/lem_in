/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.cap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:39:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/31 17:13:53 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_new_room(void)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = NULL;
	room->ant = 0;
	room->ind = 0;
	room->st_en = -1;
	room->x = 0;
	room->y = 0;
	room->next = NULL;
	return (room);
}

int			**ft_new_map(size_t size, int n)
{
	int **new;
	int i;
	int j;

	i = 0;
	new = (int **)malloc(sizeof(int*) * size);
	while (i < size)
	{
		j = 0;
		new[i] = (int *)malloc(sizeof(int) * size);
		while (j < size)
			new[i][j++] = n;
		i++;
	}
	return (new);
}

t_road		*ft_new_road(void)
{
	t_road *road;

	road = (t_road*)malloc(sizeof(t_road));
	road->ind = NULL;
	road->s_ind = 0;
	road->len = 0;
	road->next = 0;
	return (road);
}