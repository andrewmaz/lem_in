/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:08:34 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/01 12:43:59 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_rooms(t_room *room, char *str, int *s_e)
{
	if (!(room = ft_read_rooms(str, room, *s_e)))
		exit(1);
	*s_e = -1;
	return (room);
}

int		**ft_map(t_room *room, int **map, size_t *c_room, char *str)
{
	if (!map)
	{
		*c_room = ft_room_count(room);
		map = ft_new_map(*c_room, 0);
	}
	if (!ft_read_connection(room, map, *c_room, str))
		exit(1);
	return (map);
}

int		ft_sharp(char *str)
{
	int s_e;

	s_e = -1;
	if (str[0] == '#' && str[1] == '#' && str[2] != '#')
	{
		if (ft_strequ(str + 2, "start"))
			s_e = 0;
		else if (ft_strequ(str + 2, "end"))
			s_e = 1;
	}
	else if (str[0] == '#' && str[1] != '#')
		s_e = -1;
	else
		s_e = -2;
	return (s_e);
}

ssize_t	ft_non_sharp(t_room **room, int ***map, int *s_e, char *str)
{
	size_t	c_room;

	c_room = 0;
	if (ft_num_word(str, ' ') == 3)
		*room = ft_rooms(*room, str, s_e);
	else if (ft_num_word(str, '-') == 2 && \
						ft_num_word(str, ' ') == 1 && *s_e == -1)
		*map = ft_map(*room, *map, &c_room, str);
	else
	{
		*s_e != -1 ? ft_st_en_err(*room, *map, c_room, str) : \
						ft_read_line_err(*room, *map, c_room, str);
		return (0);
	}
	return (1);
}

char	*ft_realcat(char *input, char *str)
{
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str) + 1));
	input = ft_strcat(input, str);
	input = ft_strcat(input, "\n");
	return (input);
}
