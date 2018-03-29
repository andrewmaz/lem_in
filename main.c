/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/29 18:01:24 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

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

char	**ft_newrealloc(char** dstr, int size)
{
	char	**new;
	int 	i;

	i = 0;
	new = (char**)malloc(sizeof(char*) * size + 1);
	while (new[i])
		new[i++] = NULL;
	i = 0;
	if (dstr && *dstr)
	{
		while (dstr[i])
		{
			new[i] = dstr[i];
			i++;
		}
		free(dstr);
	}
	return (new);
}

int		main(int argc, char *argv[])
{
	size_t	ants;
	char	*str;
	t_room	*room;
	int 	**map;
	size_t	c_room;
	int s_e;
	char **input;
	int 	i;

	i = 1;
	room = NULL;
	map = NULL;
	s_e = -1;
	int fd = open("../map/subjet1.map", O_RDONLY);
	if (fd < 0)
		perror("Error");
	ants = ft_read_ants(fd);
	input = NULL;
	while (get_next_line(fd, &str))
	{
		i++;
		input = ft_newrealloc(input, i);
		input[i - 1] = str;
	}

	/*
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
	 */
	for (int i = 0; i < c_room; ++i)
	{
		for (int j = 0; j < c_room; ++j)
		{
			ft_printf("%d ", map[i][j]);
		}
		ft_printf("\n");
	}
	//system("leaks lem_in_f");

}