/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lee_algor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:55:51 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:05:44 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_mod(int **map, int **nmap, size_t n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j])
				nmap[i][j] = nmap[j][j];
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < n)
		nmap[i][i] = -1;
}

int			**ft_lee_algor(int s, int **map, size_t n)
{
	int **nmap;
	int i;
	int j;

	nmap = ft_new_map(n, -1);
	i = s;
	nmap[s][s] = 0;
	ft_len(s, nmap, map, n);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (map[i][j] == 1)
				ft_len(j, nmap, map, n);
			j++;
		}
		i++;
	}
	ft_mod(map, nmap, n);
	ft_del_map(map, n);
	return (nmap);
}