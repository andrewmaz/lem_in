/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:30:57 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/28 14:38:58 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "libftprintf/libft/libft.h"

typedef struct	s_ind
{
  char			*name;
  int 			ind;
  struct s_ind	*next;
}				t_ind;

typedef struct	s_room
{
  char			*name_room;
  int			ind;
  int			st_en;
  ssize_t		x;
  ssize_t 		y;
  int			ant;
  struct s_room	*next;
}				t_room;

t_room		*ft_new_room(void);
t_room		*ft_add_room(t_room *room);

#endif