/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:55:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/03 15:27:54 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t		ft_read_ants(int fd, char **input)
{
	size_t	ants;
	char	*str;

	get_next_line(fd, &str);
	if (!ft_is_number(str, 0))
		ft_read_ant_err(str);
	ants = (size_t)ft_atoi(str);
	ants > 4294967295 ? ft_read_ant_err(str) : 0;
	*input = ft_strjoin(str, "\n");
	ft_strdel(&str);
	return (ants);
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
	room->name = ft_strdup(tmp[0]);
	if (!ft_is_number(tmp[1], 1) || !ft_is_number(tmp[2], 1))
		return (ft_read_room_err(head, tmp, str));
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	room->st_en = s_e;
	ft_del_dstr(tmp);
	return (!ft_is_int(room->x) || !ft_is_int(room->y) ? \
			ft_read_room_err(head, NULL, str) : head);
}

int			ft_check_s_e(t_room *room, int **map, size_t size, char *str)
{
	int s;
	int e;

	s = 0;
	e = 0;
	while (room)
	{
		if (room->st_en == 0)
			s++;
		else if (room->st_en == 1)
			e++;
		room = room->next;
	}
	if (s == 1 && e == 1)
		return (1);
	else
		return (ft_st_en_err(room, map, size, str));
}

void		*ft_read_connection(t_room *room, int **map, size_t size, char *str)
{
	int		i;
	int		j;
	char	**tmp;

	if (!ft_check_s_e(room, map, size, str))
		return (0);
	tmp = ft_strsplit(str, '-');
	i = ft_search_ind(tmp[0], room);
	j = ft_search_ind(tmp[1], room);
	ft_del_dstr(tmp);
	if (i >= 0 && j >= 0)
	{
		map[i][j] = 1;
		map[j][i] = 1;
	}
	else
		return (ft_read_conn_err(room, map, size, str));
	return ((void*)1);
}

void		ft_read_all(t_room **room, int ***map, char **input, int fd)
{
	char	*str;
	ssize_t	c_room;
	int		s_e;

	s_e = -1;
	c_room = ft_room_count(*room);
	while (get_next_line(fd, &str))
	{
		if (str[0] != '#')
		{
			if (!ft_non_sharp(room, map, &s_e, str))
				ft_exit(input);
		}
		else
		{
			if ((s_e = ft_sharp(str)) == -2)
			{
				ft_read_line_err(*room, *map, (size_t)c_room, str);
				ft_exit(input);
			}
		}
		*input = ft_realcat(*input, str);
		ft_strdel(&str);
	}
}
