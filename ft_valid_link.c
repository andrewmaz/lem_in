/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:47:37 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:47:37 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_valid_nmap(int s, int e, int **map, size_t n)
{
	int j;
	int vs;
	int ve;

	vs = 0;
	ve = 0;
	j = 0;
	while (j < n)
	{
		if (map[s][j] > -1)
			vs = 1;
		if (map[e][j] > -1)
			ve = 1;
		j++;
	}
	return (vs && ve);
}
