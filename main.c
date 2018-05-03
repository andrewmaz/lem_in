/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:27:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 18:35:11 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int argc, char *argv[])
{
	t_fflag	*flag;
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
	flag->ant_room_fd[2] = flag->f ? ft_read_fd(flag, flag->filename, 1) : 0;
	flag->ant_room_fd[3] = flag->o ? ft_read_fd(flag, flag->fileout, 0) : 1;
	flag->ant_room_fd[0] = ft_read_ants((int)flag->ant_room_fd[2], &input);
	ft_read_all(&room, &map, &input, (int)flag->ant_room_fd[2]);
	flag->ant_room_fd[1] = ft_room_count(room);
	ft_output(flag, room, map, input);
	close((int)flag->ant_room_fd[2]);
	close((int)flag->ant_room_fd[3]);
	free(flag);
	return (0);
}
