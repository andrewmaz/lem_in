/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:46:18 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:20:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*ft_intrealloc(int *arr, int oldsize)
{
	int *new;
	int i;

	i = 0;
	new = (int*)malloc(sizeof(int) * (oldsize + 1));
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

char	*ft_realcat(char *input, char *str)
{
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str)));
	input = ft_strcat(input, str);
	return (input);
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
