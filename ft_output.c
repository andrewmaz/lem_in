/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:29:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 18:23:04 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			break ;
	}
}

void		ft_creat_res(t_fflag *flag, t_road *road, char *res, char *e)
{
	char	*ito;

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
	ft_print_result(flag, &res, e);
}

static int	ft_go(t_fflag *flag, t_road *road, int *n, char *e)
{
	t_road	*head;

	head = road;
	if (flag->ant_room_fd[0] == ft_in_finish(road))
		return (0);
	while (road && road->room)
	{
		while (road->room->next)
			road->room = road->room->next;
		road->room->antn = 0;
		ft_help_go(road, n);
		road = road->next;
	}
	ft_creat_res(flag, head, NULL, e);
	return (1);
}

static void	ft_set_ants(t_road *road, size_t ants)
{
	while (ants > 0)
	{
		while (road && road->prev)
			road = road->prev;
		while (road && road->next && ants > 0)
		{
			if (road->len + road->ant_num + (road->len != road->next->len ? \
			1 : 0) <= road->next->len + road->next->ant_num)
			{
				road->ant_num++;
				ants--;
				while (road && road->prev)
					road = road->prev;
			}
			else
				road = road->next;
		}
		if (ants > 0 && road)
		{
			road->ant_num++;
			ants--;
		}
	}
}

void		ft_output(t_fflag *flag, t_room *room, int **map, char *input)
{
	t_road	*road;
	int		i;
	int		j;
	int		n;

	i = 1;
	j = 1;
	n = 0;
	map = ft_lee_algor(ft_search_st_en(room, 0), map, flag->ant_room_fd[1]);
	ft_valid_link(room, map, flag->ant_room_fd, input);
	road = ft_read_road(room, map, flag->ant_room_fd);
	!road ? ft_input_err(room, map, input, "No road") : 0;
	ft_putendl_fd(input, (int)flag->ant_room_fd[3]);
	ft_set_ants(road, flag->ant_room_fd[0]);
	ft_create_road(road, room);
	while (i)
	{
		i = ft_go(flag, road, &j, \
				ft_search_room(ft_search_st_en(room, 1), room)->name);
		n++;
	}
	ft_print_bonus(n - 1, flag, road, room);
	ft_del_road(road);
	ft_del_all(room, map, flag->ant_room_fd[1], input);
}
