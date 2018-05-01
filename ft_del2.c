/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:58:49 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:12:36 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_del_last_road(t_road **road)
{
	t_road *tmp;

	tmp = *road;
	if (tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		ft_del_road(tmp);
		return ;
	}
	else
		ft_del_road(*road);
	*road = NULL;
}
