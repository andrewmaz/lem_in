/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:30:57 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/31 17:56:13 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "libftprintf/libft/libft.h"
# include <stdio.h>

typedef struct	s_room
{
	char			*name;
	int				ind;
	int				st_en;
	ssize_t			x;
	ssize_t			y;
	int				ant;
	struct s_room	*next;
}				t_room;

t_room			*ft_new_room(void);
int				**ft_new_map(size_t	size);
t_room			*ft_add_room(t_room *room);
void			ft_read_all(t_room **room, int ***map, char **input, int fd);
size_t			ft_read_ants(int fd, char **input);
t_room			*ft_read_rooms(char *str, t_room *room, int s_e);
void			*ft_read_connection(t_room *room, int **map, size_t siz, \
					char *str);
void			ft_del_dstr(char **dstr);
void			ft_del_room(t_room *room);
void			ft_del_map(int **map, size_t size);
void			ft_del_all(t_room *room, int **map, size_t size, char *str);
void			ft_read_ant_err(char *str);
void			*ft_read_room_err(t_room *room, char **str, char *s);
void			*ft_read_conn_err(t_room *room, int **map, size_t size, \
					char *str);
int				ft_read_line_err(t_room *room, int **map, size_t size, \
					char *str);
int				ft_st_en_err(t_room *room, int **map, size_t size, char *str);
int				ft_is_number(char *nbr, int sig);
int				ft_is_int(ssize_t nbr);

ssize_t			ft_non_sharp(t_room **room, int ***map, int *s_e, char *str);
int				ft_sharp(char *str);
t_room			*ft_rooms(t_room *room, char *str, int *s_e);

size_t			ft_room_count(t_room *room);
char			*ft_search_name(int ind, t_room *room);
int				ft_search_ind(char *name, t_room *room);
void			ft_exit(char **str);
char			*ft_realcat(char *input, char *str);

#endif
