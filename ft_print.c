/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:55:36 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 14:52:18 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_swap_str(char **a, char **b)
{
	char	*c;

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
	int		i;
	int		j;

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

void		ft_print_result(t_fflag *flag, char **res, char *e)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = ft_strsplit(*res, ' ');
	ft_bubl_sort(new);
	ft_strdel(res);
	while (new[i])
	{
		j = 0;
		while (new[i][j] && new[i][j] != '-')
			j++;
		flag->c && flag->a == ft_atoi(new[i] + 1) ? ft_printf("{red}") : 0;
		flag->c && ft_strequ(new[i] + ++j, e) ? ft_printf("{green}") : 0;
		ft_printf("[fd]%s%s", flag->ant_room_fd[3], new[i], \
		new[i + 1] ? " " : "");
		flag->c && ft_strequ(new[i] + j, e) ? ft_printf("{eoc}") : 0;
		flag->c && flag->a == ft_atoi(new[i] + 1) ? ft_printf("{eoc}") : 0;
		flag->a += flag->c && flag->a == ft_atoi(new[i] + 1) ? 1 : 0;
		i++;
	}
	ft_printf("[fd]\n", flag->ant_room_fd[3]);
	ft_del_dstr(new);
}

void		ft_print_road(t_fflag *flag, t_road *road, t_room *room)
{
	char	*s;
	t_room	*ro;
	int		i;

	i = 1;
	s = ft_search_room(ft_search_st_en(room, 0), room)->name;
	while (road && road->room)
	{
		ro = road->room;
		ft_printf("%d road", i++);
		if (flag->r)
			flag->c ? ft_printf(" [{red}%s{eoc}->", s) : ft_printf(" [%s->", s);
		while (ro && flag->r)
		{
			if (flag->c && ro->st_en > 0)
				ft_printf("{green}%s{eoc}]", ro->name);
			else
				ft_printf("%s%s", ro->name, (ro->st_en == 1 ? "]" : "->"));
			ro = ro->next;
		}
		flag->l ? ft_printf(" | length %d\n", road->len) : ft_printf("\n");
		road = road->next;
	}
}

void		ft_print_bonus(int n, t_fflag *flag, t_road *road, t_room *room)
{
	char	*e;
	char	*s;

	s = ft_search_room(ft_search_st_en(room, 0), room)->name;
	e = ft_search_room(ft_search_st_en(room, 1), room)->name;
	if (flag->r)
		!flag->c ? ft_printf("\nSTART - %s\nEND - %s\n", s, e) : \
				ft_printf("\n{red}START - %s\n{green}END - %s{eoc}\n", s, e);
	if (flag->r || flag->l)
	{
		ft_printf("\n");
		ft_print_road(flag, road, room);
	}
	if (flag->n)
		ft_printf("\nTime on the road %d!\n", n);
}
