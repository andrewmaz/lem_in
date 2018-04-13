/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:57:50 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/31 15:08:28 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_del_dstr(char **dstr)
{
	int i;

	i = 0;
	while (dstr[i])
		ft_strdel(&dstr[i++]);
	free(dstr);
}

void	ft_del_map(void **map, size_t size)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (i < size)
		free(map[i++]);
	free(map);
}

void	ft_del_room(t_room *room)
{
	t_room *tmp;

	while (room)
	{
		tmp = room->next;
		ft_strdel(&room->name);
		free(room);
		room = tmp;
	}
}

void	ft_del_all(t_room *room, int **map, size_t size, char *str)
{
	ft_strdel(&str);
	ft_del_room(room);
	ft_del_map(map, size);
}
