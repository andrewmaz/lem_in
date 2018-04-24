/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 14:39:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_set_key(t_flag *flag, int i, char **v)
{
	if (v[i][1] == 'c')
		flag->c = 1;
	else if (v[i][1] == 'v')
		flag->v = 1;
	else if (v[i][1] == 'n')
		flag->n = 1;
	else if (v[i][1] == 'h')
		flag->h = 1;
	else if (v[i][1] == 'k')
		flag->k = 1;
	else if (v[i][1] == 'f')
	{
		flag->f = 1;
		flag->filename = v[++i];
	}
	else
	{
		free(flag);
		errno = 22;
		perror("Unknown key!");
		exit(1);
	}
	return (i);
}

t_flag	*ft_read_flag(int c, char **v)
{
	int		i;
	t_flag	*flag;

	flag = ft_new_flag();
	i = 1;
	while (i < c)
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			i = ft_set_key(flag, i, v);
		else
		{
			free(flag);
			errno = 22;
			perror("Unknown key!");
			exit(1);
		}
		i++;
	}
	return (flag);
}
