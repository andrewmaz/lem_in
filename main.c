/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 16:36:27 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

size_t ft_read_fd()
{
	return(0);
}

int main(int argc, char *argv[])
{
	size_t	ant_room_fd[3];
	t_flag	*flag;
	t_room	*room;
	int		**map;
	char	*input;

	input = NULL;
	room = NULL;
	map = NULL;
	flag = ft_read_flag(argc, argv);
	if (flag->h)
	{
		ft_help();
		free(flag);
		return (0);
	}
	ant_room_fd[2] = flag->f ? (size_t)open(flag->filename, O_RDONLY) : 0;
	ant_room_fd[0] = ft_read_ants((int)ant_room_fd[2], &input);
	ft_read_all(&room, &map, &input, (int)ant_room_fd[2]);
	ant_room_fd[1] = ft_room_count(room);
	ft_output(ant_room_fd, room, map, input);
	//system("leaks lem_in_f");
	return (0);
}