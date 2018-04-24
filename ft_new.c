/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.cap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:39:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/19 15:32:40 by jdoeurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_new_room(void)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = NULL;
	room->ant = 0;
	room->antn = 0;
	room->ind = 0;
	room->st_en = -1;
	room->x = 0;
	room->y = 0;
	room->next = NULL;
	room->prev = NULL;
	return (room);
}

int			**ft_new_map(size_t size, int n)
{
	int **new;
	size_t i;
	size_t j;

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
	road->road = NULL;
	road->room = NULL;
	road->ant_num = 0;
	road->len = 0;
	road->room = NULL;
	road->next = NULL;
	road->prev = NULL;
	return (road);
}

t_flag	*ft_new_flag(void)
{
	t_flag *key;

	key = (t_flag*)malloc(sizeof(t_flag));
	key->c = 0;
	key->n = 0;
	key->v = 0;
	key->h = 0;
	key->f = 0;
	key->k = 0;
	key->filename = NULL;
	return (key);
}
