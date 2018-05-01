/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_input_err(t_room *room, int **map, char *str, char *out)
{
	errno = 5;
	ft_del_all(room, map, ft_room_count(room), str);
	perror(out);
	exit(1);
}

void	ft_no_ants(char *str)
{
	errno = 5;
	ft_strdel(&str);
	perror("No ants");
}

void	ft_exit(char **str)
{
	ft_strdel(str);
	exit(1);
}
