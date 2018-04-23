/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:48:38 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	size_t ants;
	t_room *room;
	int **map;
	char *input;
	size_t c_rooms;
	t_road *road;

	input = NULL;
	room = NULL;
	road = NULL;
	map = NULL;
	///
	int fd = open("../map/subjet2.map", O_RDONLY);
	if (fd < 0)
		perror("Error");
	///
	ants = ft_read_ants(fd, &input);
	ft_read_all(&room, &map, &input, fd);
	c_rooms = ft_room_count(room);
	int s = ft_search_st_en(room, 0);
	int e = ft_search_st_en(room, 1);
	map = ft_lee_algor(s, map, c_rooms);
	if (!ft_valid_nmap(s, e, map, c_rooms))
	{
		ft_st_en_err(room, map, c_rooms, input);
		system("leaks lem_in_f");
		exit(1);
	}
	ft_putstr(input);
	while (ft_min_len(s, map, c_rooms) != -1 && ft_min_len(e, map, c_rooms) != -1)
	{
		road = ft_search_road(road, e, map, c_rooms);
		if (road->len == 1)
			break;
	}
	ft_output(ants, road, room);
	ft_del_all(room, map, c_rooms, input);
	ft_del_road(road);
	//system("leaks lem_in_f");
	return (0);
}