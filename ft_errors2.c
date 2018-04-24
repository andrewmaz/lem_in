/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 17:00:01 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_noants_err(char **input)
{
	errno = 5;
	ft_strdel(input);
	perror("No ants");
	exit(1);
}

void		ft_emptyfile_err(char **input)
{
	errno = 5;
	ft_strdel(input);
	perror("Empty file");
	exit(1);
}

void		ft_noroom_err(char **input)
{
	errno = 5;
	ft_strdel(input);
	perror("No rooms");
	exit(1);
}

void		ft_nolinks_err(char **input)
{
	errno = 5;
	ft_strdel(input);
	perror("No links");
	exit(1);
}

void		ft_noroad_err(t_room *room, int **map, size_t size, char *str)
{
	errno = 5;
	ft_del_all(room, map, size, str);
	perror("No road");
	exit(1);
}
