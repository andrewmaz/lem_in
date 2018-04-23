/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:29:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:44:32 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print(t_road *road, char *res, char *ito)
{
	while (road && road->room)
	{
		while (road->room->next)
			road->room = road->room->next;
		while (road->room)
		{
			if (road->room->ant && road->room->antn)
			{
				res = res ? ft_realcat(res, " ") : res;
				res = ft_realcat(res, "L");
				ito = ft_itoa(road->room->antn);
				res = ft_realcat(res, ito);
				ft_strdel(&ito);
				res = ft_realcat(res, "-");
				res = ft_realcat(res, road->room->name);
			}
			if (!road->room->prev)
				break ;
			road->room = road->room->prev;
		}
		road = road->next;
	}
	ft_putendl(res);
	ft_strdel(&res);
}

static void	ft_help_go(t_road *road, int *n)
{
	while (1)
	{
		if ((road->room->ant == 0 || road->room->st_en == 1))
		{
			if (road->room->prev && road->room->prev->ant == 1)
			{
				road->room->prev->ant--;
				road->room->ant++;
				road->room->antn = road->room->prev->antn;
				road->room->prev->antn = 0;
			}
			else if (road->ant_num && !road->room->prev)
			{
				road->ant_num--;
				road->room->ant++;
				road->room->antn = (*n)++;
			}
		}
		if (road->room->prev)
			road->room = road->room->prev;
		else
			break;
	}
}

static int	ft_go(size_t ants, t_road *road, int *n)
{
	t_road *head;

	head = road;
	if (ants == ft_in_finish(road))
		return (0);
	while (road && road->room)
	{
		while (road->room->next)
			road->room = road->room->next;
		road->room->antn = 0;
		ft_help_go(road, n);
		road = road->next;
	}
	ft_print(head, NULL, NULL);
	return (1);
}

static void	ft_set_ants(t_road *road, size_t ants)
{
	int len;

	while (ants > 0)
	{
		while (road->next)
			road = road->next;
		len = (road && road->prev) ? road->len - road->prev->len : 0;
		while (road && road->prev && ants > 0)
		{
			if (road->ant_num + len < road->prev->ant_num)
			{
				road->ant_num++;
				ants--;
			}
			else
				road = road->prev;
		}
		if (ants > 0 && road)
		{
			road->ant_num++;
			ants--;
		}
	}
}

void ft_output(size_t ants, t_road *road, t_room *room)
{
	int i;
	int j;

	i = 1;
	j = 1;
	ft_set_ants(road, ants);
	ft_create_road(road, room);
	ft_putstr("\n");
	while (i)
		i = ft_go(ants, road, &j);
}