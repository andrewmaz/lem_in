/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:30:57 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/23 16:33:13 by amazurok         ###   ########.fr       */
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
	size_t			ant;
  	int 			antn;
	struct s_room	*next;
  	struct s_room	*prev;

}				t_room;

typedef struct	s_road
{
  int			ant_num;
  t_room		*room;
  int			*road;
  int			len;
  struct s_road *next;
  struct s_road *prev;
}				t_road;

t_room			*ft_new_room(void);
t_road			*ft_new_road(void);
int				**ft_new_map(size_t	size, int n);
t_room			*ft_add_room(t_room *room);
void			ft_read_all(t_room **room, int ***map, char **input, int fd);
size_t			ft_read_ants(int fd, char **input);
t_room			*ft_read_rooms(char *str, t_room *room, int s_e);
void			*ft_read_connection(t_room *room, int **map, size_t siz, \
					char *str);
void			ft_del_road(t_road *road);
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
int				ft_search_st_en(t_room *room, int s_e);
t_room			*ft_search_room(int ind, t_room *room);
t_road			*ft_search_road(t_road *head, int e, int **map, size_t n);

int				ft_st_en_err(t_room *room, int **map, size_t size, char *str);
int				ft_is_number(char *nbr, int sig);
int				ft_is_int(ssize_t nbr);
size_t			ft_in_finish(t_road *road);

ssize_t			ft_non_sharp(t_room **room, int ***map, int *s_e, char *str);
int				ft_sharp(char *str, int s_e);
t_room			*ft_rooms(t_room *room, char *str, int *s_e);
void ft_create_road(t_road *road, t_room *room);
void ft_output(size_t ants, t_road *road, t_room *room);
int ft_valid_nmap(int s, int e, int **map, size_t n);

size_t			ft_room_count(t_room *room);
int				ft_search_ind(char *name, t_room *room);
void			ft_exit(char **str);
char			*ft_realcatendl(char *input, char *str);
int 			*ft_intrealloc(int *arr, int oldsize);
char	*ft_realcat(char *input, char *str);
int ft_min_len(int i, int **map, size_t n);
int *ft_revers(int *in, int size);
void ft_len(int s, int **nmap, int **map, size_t size);
int		**ft_lee_algor(int s, int **map, size_t n);

#endif
