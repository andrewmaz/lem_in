/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lee_algor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:55:51 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:24:03 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_mod(int **map, int **nmap, size_t n)
{
	size_t i;
	size_t j;

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
	i = 0;
	while (i < n)
	{
		nmap[i][i] = -1;
		i++;
	}
}

int			ft_src(int no, int len, int **nmap, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if (i <= no)
			i++;
		if (i < (int)n && nmap[i][i] == len && i > no)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_max_in_map(int **nmap, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = nmap[i][i];
	while (i < n)
	{
		if (nmap[i][i] > res)
			res = nmap[i][i];
		i++;
	}
	return (res);
}

int			**ft_lee_algor(int s, int **map, size_t n)
{
	int len;
	int i;
	int j;
	int **nmap;

	i = s;
	len = 0;
	nmap = ft_new_map(n, -1);
	nmap[s][s] = 0;
	while (i < (int)n)
	{
		j = 0;
		while (j < (int)n)
		{
			if (map[i][j])
				nmap[j][j] = ft_min(len + 1, nmap[j][j]);
			j++;
		}
		while ((i = ft_src(i, len, nmap, n)) < 0)
		{
			len++;
			if ((len - ft_max_in_map(nmap, n)) > 1)
				break ;
		}
		if ((len - ft_max_in_map(nmap, n)) > 1)
			break ;
	}
	ft_mod(map, nmap, n);
	ft_del_map(map, n);
	return (nmap);
}
