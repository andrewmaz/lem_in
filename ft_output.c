/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:29:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 11:38:13 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_swap_str(char **a, char **b)
{
	char *c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
	else
		return ;
}

static void	ft_bubl_sort(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr && arr[i])
	{
		j = 0;
		while (arr[j + 1])
		{
			if (ft_atoi(arr[j] + 1) > ft_atoi(arr[j + 1] + 1))
				ft_swap_str(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

char *ft_dstr2str(char **dstr)
{
	char	*res;
	int 	i;

	i = 0;
	res = NULL;
	while (dstr[i])
	{
		res = ft_realcat(res, dstr[i++]);
		res = dstr[i] ? ft_realcat(res, " ") : res;
	}
	return (res);
}

void		ft_sort_res(char **res)
{
	char **new;

	new = ft_strsplit(*res, ' ');
	ft_bubl_sort(new);
	ft_strdel(res);
	*res = ft_dstr2str(new);
	ft_del_dstr(new);
}

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
	ft_sort_res(&res);
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
	while (ants > 0)
	{
		while (road && road->prev)
			road = road->prev;
		while (road && road->next && ants > 0)
		{
			if (road->len + road->ant_num + 1 <= \
				road->next->len + road->next->ant_num)
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

void ft_output(size_t *ant_room_fd, t_room *room, int **map, char *input)
{
	t_road	*road;
	int		i;
	int		j;

	i = 1;
	j = 1;
	ft_valid_link(room, map, ant_room_fd, input);
	map = ft_lee_algor(ft_search_st_en(room, 0), map, ant_room_fd[1]);
	ft_valid_link(room, map, ant_room_fd, input);
	road = ft_read_road(room, map, ant_room_fd);
	!road ? ft_input_err(room, map, input, "No road") : 0;
	ft_putstr(input);
	ft_set_ants(road, ant_room_fd[0]);
	ft_create_road(road, room);
	ft_putstr("\n");
	while (i)
	{
		i = ft_go(ant_room_fd[0], road, &j);
	}
	ft_del_road(road);
	ft_del_all(room, map, ant_room_fd[1], input);
}