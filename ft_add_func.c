/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:46:18 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/31 17:10:13 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_room_count(t_room *room)
{
	size_t	i;

	i = 0;
	while (room)
	{
		i++;
		room = room->next;
	}
	return (i);
}

int		ft_search_ind(char *name, t_room *room)
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

char	*ft_search_name(int ind, t_room *room)
{
	while (room)
	{
		if (ind == room->ind)
			return (room->name);
		room = room->next;
	}
	return (NULL);
}

void	ft_exit(char **str)
{
	ft_strdel(str);
	exit(1);
}
