/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:20:12 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 13:37:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_ant_err(char *str)
{
	errno = 5;
	ft_strdel(&str);
	perror("Number of ants must be a positive integer!");
	exit(1);
}

void		*ft_read_room_err(t_room *room, char **str, char *s, int r_c)
{
	errno = 5;
	ft_strdel(&s);
	ft_del_room(room);
	str ? ft_del_dstr(str) : 0;
	r_c ? perror("The rooms coordinates will always be integers!") : \
		perror("The rooms name/coordinates already exist!");
	return (NULL);
}

void		*ft_read_conn_err(t_room *room, int **map, size_t size, char *str)
{
	errno = 5;
	ft_del_all(room, map, size, str);
	perror("Room name not found!");
	return (NULL);
}

int			ft_read_line_err(t_room *room, int **map, size_t size, char *str)
{
	errno = 5;
	ft_del_all(room, map, size, str);
	perror("Doesn't valid line!");
	return (1);
}

int			ft_st_en_err(t_room *room, int **map, size_t size, char *str)
{
	errno = 5;
	ft_del_all(room, map, size, str);
	perror("Doesn't valid start/end!");
	return (0);
}
