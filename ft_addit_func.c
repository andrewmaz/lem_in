/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:46:18 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/11 12:43:18 by jdoeurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	*ft_intrealloc(int *arr, int oldsize)
{
	int *new;
	int i;

	i = 0;
	new = (int*)malloc(sizeof(int) * oldsize + 1);
	if (arr)
	{
		while (i < oldsize)
		{
			new[i] = arr[i];
			i++;
		}
		free(arr);
	}
	return (new);
}

char	*ft_realcatendl(char *input, char *str)
{
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str) + 1));
	input = ft_strcat(input, str);
	input = ft_strcat(input, "\n");
	return (input);
}

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
	system("leaks lem_in_f");
	exit(1);
}
