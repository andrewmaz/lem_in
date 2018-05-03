/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/03 15:16:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_read_fd(t_fflag *flag, char *name, int f)
{
	int		fd;
	char	*tmp;

	if ((fd = open(name, O_RDWR)) > 0)
		return ((size_t)fd);
	else if (!f && flag->fileout && flag->fileout[0] != '-')
	{
		tmp = ft_strjoin("touch ", name);
		system(tmp);
		ft_strdel(&tmp);
		return ((size_t)open(name, O_RDWR));
	}
	ft_fd_err(flag);
	return (0);
}

int		ft_set_key(t_fflag *flag, int i, char **v)
{
	if (v[i][1] == 'c')
		flag->c = 1;
	else if (v[i][1] == 'l')
		flag->l = 1;
	else if (v[i][1] == 'n')
		flag->n = 1;
	else if (v[i][1] == 'h')
		flag->h = 1;
	else if (v[i][1] == 'r')
		flag->r = 1;
	else if (v[i][1] == 'f')
	{
		flag->f = 1;
		flag->filename = v[++i];
	}
	else if (v[i][1] == 'o')
	{
		flag->o = 1;
		flag->fileout = v[++i];
	}
	else
		ft_key_err(flag);
	return (i);
}

t_fflag	*ft_read_flag(int c, char **v)
{
	int		i;
	t_fflag	*flag;

	flag = ft_new_fflag();
	i = 1;
	while (i < c)
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			i = ft_set_key(flag, i, v);
		else
			ft_key_err(flag);
		i++;
	}
	return (flag);
}
