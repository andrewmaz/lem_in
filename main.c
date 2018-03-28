/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/28 18:24:30 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

size_t	ft_read_ants(char *str)
{
	size_t	ants;
	int		i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			exit(1);
	ants = (size_t)ft_atoi(str);
	return (ants);
}

void	ft_del_dstr(char **dstr)
{
	int i;

	i = 0;
	while (dstr[i])
		ft_strdel(&dstr[i++]);
	free(dstr);
}

t_room	*ft_read_rooms(char *str, t_room *room, int s_e)
{
	char	**tmp;
	t_room	*head;

	room = ft_add_room(room);
	head = room;
	while (room->next)
		room = room->next;
	tmp = ft_strsplit(str, ' ');
	room->name_room = ft_strdup(tmp[0]);
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	room->st_en = s_e;
	ft_del_dstr(tmp);
	return (head);
}

int 	**ft_new_map(size_t	size)
{
	int **new;
	int i;
	int j;

	i = 0;
	new = (int **)malloc(sizeof(int*) * size);
	while (i < size)
	{
		j = 0;
		new[i] = (int *)malloc(sizeof(int) * size);
		while (j < size)
			new[i][j++] = 0;
		i++;
	}
	return (new);
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
	while(room)
	{
		if (ft_strequ(name, room->name_room))
			i = room->ind;
		room = room->next;
	}
	return (i);
}

void 	ft_read_connection(char *str, int **map, t_room *room)
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

int		main(int argc, char *argv[])
{
	size_t	ants;
	char	*str;
	t_room	*room;
	int 	**map;
	size_t	c_room;
	int s_e;

	room = NULL;
	map = NULL;
	s_e = -1;
	int fd = open("../map/subjet1.map", O_RDONLY);
	get_next_line(fd, &str);
	ants = ft_read_ants(str);
	ft_putendl(str);
	ft_strdel(&str);
	while (get_next_line(fd, &str))
	{
		if (str[0] != '#')
		{
			if (ft_num_word(str, ' ') == 3)
			{
				room = ft_read_rooms(str, room, s_e);
				s_e = -1;
			}
			else if (ft_num_word(str, '-') == 2)
			{
				if (!map)
				{
					c_room = ft_room_count(room);
					map = ft_new_map(c_room);
				}
				ft_read_connection(str, map, room);
			}
			else
				exit(1);
		}
		else
		{
			if (str[1] == '#')
				s_e = (str[2] == 'e');
		}
		ft_putendl(str);
		ft_strdel(&str);
	}
	for (int i = 0; i < c_room; ++i)
	{
		for (int j = 0; j < c_room; ++j)
		{
			ft_printf("%d ", map[i][j]);
		}
		ft_printf("\n");
	}
}