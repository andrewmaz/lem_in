/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/31 17:38:42 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

void	ft_algor(size_t ants, t_room *room, int **map, size_t c_rooms)
{

}

int		main(int argc, char *argv[])
{
	size_t	ants;
	t_room	*room;
	int 	**map;
	char	*input;
	size_t	c_rooms;

	input = NULL;
	room = NULL;
	map = NULL;
	///
	int fd = open("../map/subjet1.map", O_RDONLY);
	if (fd < 0)
		perror("Error");
	///
	ants = ft_read_ants(fd, &input);
	ft_read_all(&room, &map, &input, fd);
	c_rooms = ft_room_count(room);
	ft_putstr(input);
	ft_algor(ants, room, map, c_rooms);
	for (int i = 0; i < c_rooms; ++i)
	{
		for (int j = 0; j < c_rooms; ++j)
		{
			ft_printf("%d ", map[i][j]);
		}
		ft_printf("\n");
	}
	ft_del_all(room, map, c_rooms, input);
	//system("leaks lem_in_f");
	return (0);
}