/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:30:57 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/29 15:36:21 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
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
int			**ft_new_map(size_t	size);
t_room		*ft_add_room(t_room *room);
size_t		ft_read_ants(int fd);
t_room		*ft_read_rooms(char *str, t_room *room, int s_e);
void	 	ft_read_connection(char *str, int **map, t_room *room);
void		ft_del_dstr(char **dstr);
int			ft_search_ind(char *name, t_room *room);

int			ft_is_number(char *nbr, int sig);
#endif