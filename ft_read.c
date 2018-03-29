/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:55:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/29 17:41:49 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"
#include <errno.h>

void		ft_read_ant_err(char *str)
{
	errno = 5;
	ft_strdel(&str);
	perror("Number of ants must be a positive integer!");
	system("leaks lem_in_f");
	exit(1);
}

void		ft_read_room_err(char **str, char *s)
{
	errno = 5;
	ft_strdel(&s);
	ft_del_dstr(str);
	perror("The rooms coordinates will always be integers!");
	system("leaks lem_in_f");
	exit(1);
}

int			ft_is_int(ssize_t nbr)
{
	return (nbr <= 2147483647 && nbr >= -2147483648);
}

size_t		ft_read_ants(int fd)
{
	size_t	ants;
	char 	*str;

	get_next_line(fd, &str);
	if (!ft_is_number(str, 0))
		ft_read_ant_err(str);
	ants = (size_t)ft_atoi(str);
	ants > 4294967295 ? ft_read_ant_err(str) : 0;
	ft_putendl(str);
	ft_strdel(&str);
	return (ants);
}

int			ft_is_number(char *nbr, int sig)
{
	int i;

	i = 0;
	if (sig)
	{
		while (nbr[i] == '-')
			i++;
		while (nbr[i])
			if (!ft_isdigit(nbr[i++]))
				return (0);
	}
	else
		while (nbr[i] == '+')
			i++;
	while (nbr[i])
		if (!ft_isdigit(nbr[i++]))
			return (0);
	return (1);
}

t_room		*ft_read_rooms(char *str, t_room *room, int s_e)
{
	char	**tmp;
	t_room	*head;

	room = ft_add_room(room);
	head = room;
	while (room->next)
		room = room->next;
	tmp = ft_strsplit(str, ' ');
	room->name_room = ft_strdup(tmp[0]);
	if (!ft_is_number(tmp[1], 1) || !ft_is_number(tmp[2], 1))
		ft_read_room_err(tmp, str);
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	!ft_is_int(room->x) || !ft_is_int(room->y) ? ft_read_room_err(tmp, str) : 0;
	room->st_en = s_e;
	ft_del_dstr(tmp);
	return (head);
}

void 		ft_read_connection(char *str, int **map, t_room *room)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_strsplit(str, '-');
	i = ft_search_ind(tmp[0], room);
	j = ft_search_ind(tmp[1], room);
	ft_del_dstr(tmp);
	if (i >= 0 && j >= 0)
	{
		map[i][j] = 1;
		//map[j][i] = 1;
	}
	else
		exit(1);
}
