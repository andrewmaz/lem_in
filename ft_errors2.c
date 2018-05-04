/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/04 12:08:22 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_input_err(t_room *room, int **map, char *str, char *out)
{
	errno = 5;
	ft_del_all(room, map, ft_room_count(room), str);
	perror(out);
	ft_exit(NULL);
}

void	ft_no_ants(char *str)
{
	errno = 5;
	ft_strdel(&str);
	perror("No ants");
}

void	ft_key_err(t_fflag *flag)
{
	free(flag);
	errno = 22;
	perror("Unknown key!");
	ft_help();
	ft_exit(NULL);
}

void	ft_fd_err(t_fflag *flag)
{
	perror("Error!");
	if (flag)
		free(flag);
	ft_exit(NULL);
}

void	ft_exit(char **str)
{
	ft_strdel(str);
	exit(1);
}
