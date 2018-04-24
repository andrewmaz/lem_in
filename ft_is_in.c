/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:43:10 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 15:34:07 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_int(ssize_t nbr)
{
	return (nbr <= 2147483647 && nbr >= -2147483648);
}

int			ft_is_number(char *nbr, int sig)
{
	int i;

	i = 0;
	if (!nbr)
		return (1);
	if (sig)
	{
		if (nbr[i] == '+' || nbr[i] == '-')
			i++;
		while (nbr[i])
			if (!ft_isdigit(nbr[i++]))
				return (0);
	}
	else
	{
		if (nbr[i] == '+')
			i++;
		while (nbr[i])
			if (!ft_isdigit(nbr[i++]))
				return (0);
	}
	return (1);
}

size_t ft_in_finish(t_road *road)
{
	size_t ret;
	t_room *tmp;

	ret = 0;
	while (road)
	{
		if (!(tmp = road->room))
			break;
		while (tmp->next)
			tmp = tmp->next;
		ret += tmp->ant;
		road = road->next;
	}
	return (ret);
}
