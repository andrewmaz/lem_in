/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:08:34 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 18:25:40 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_rooms(t_room *room, char *str, int *s_e)
{
	if (!(room = ft_read_rooms(str, room, *s_e)))
		ft_exit(NULL);
	*s_e = -1;
	return (room);
}

int			**ft_map(t_room *room, int **map, size_t c_room, char *str)
{
	!room ? ft_input_err(NULL, NULL, str, "No rooms") : 0;
	if (!map)
		map = ft_new_map(c_room, 0);
	if (!ft_read_connection(room, map, c_room, str))
		ft_exit(NULL);
	return (map);
}

int			ft_sharp(char *str, int s)
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
	else
		s_e = -1;
	return (s != -1 ? -3 : s_e);
}

ssize_t		ft_non_sharp(t_room **room, int ***map, int *s_e, char *str)
{
	if (ft_num_word(str, ' ') == 3)
	{
		*map ? ft_input_err(*room, *map, str, "Doesn't valid link!") : 0;
		*room = ft_rooms(*room, str, s_e);
	}
	else if (ft_num_word(str, '-') == 2 && \
						ft_num_word(str, ' ') == 1 && *s_e == -1)
		*map = ft_map(*room, *map, ft_room_count(*room), str);
	else
	{
		*s_e != -1 ? ft_st_en_err(*room, *map, ft_room_count(*room), str) : \
					ft_read_line_err(*room, *map, ft_room_count(*room), str);
		return (0);
	}
	*s_e = -1;
	return (1);
}

t_road		*ft_read_road(t_room *room, int **map, size_t *ant_room_fd)
{
	t_road	*road;
	size_t	i;
	int		s;
	int		e;

	i = 0;
	s = ft_search_st_en(room, 0);
	e = ft_search_st_en(room, 1);
	road = NULL;
	while (ft_min_len(s, map, ant_room_fd[1]) != -1 && \
			ft_min_len(e, map, ant_room_fd[1]) != -1 && i <= ant_room_fd[0])
	{
		road = ft_search_road(road, e, map, ant_room_fd[1]);
		if (map[ft_in_last_road(road)][s] == -1)
			ft_del_last_road(&road);
		if (road && road->len == 1)
		{
			map[s][e] = -1;
			map[e][s] = -1;
		}
		i++;
	}
	road = ft_sort_road(road);
	return (road);
}
