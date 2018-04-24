/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:24:35 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 17:27:25 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_link_err(t_room *room, int **map, size_t size, char *str)
{
	errno = 5;
	ft_del_all(room, map, size, str);
	perror("Doesn't valid link!");
	exit(1);
}