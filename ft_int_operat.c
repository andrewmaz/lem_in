/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_operat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:41:04 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/01 14:21:20 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_swap_int(int *a, int *b)
{
	int c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
	else
		return ;
}

int		ft_min(int a, int b)
{
	if (a < 0)
		return (b);
	else if (b < 0)
		return (a);
	else if (a < b)
		return (a);
	else
		return (b);
}

int		*ft_revers(int *in, int size)
{
	int i;

	i = 0;
	size--;
	while (i < size)
	{
		ft_swap_int(&in[i++], &in[size--]);
	}
	return (in);
}

int		ft_min_len(int i, int **map, size_t n)
{
	size_t	j;
	int		res;

	j = 0;
	res = map[i][j];
	while (j < n)
	{
		if (map[i][j] != -1)
			res = ft_min(res, map[i][j]);
		j++;
	}
	return (res);
}
