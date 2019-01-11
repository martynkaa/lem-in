/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:32:10 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/24 09:32:11 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"
# include <stdio.h>

# define RED        "\x1b[31m"
# define GREEN        "\x1b[32m"
# define YELLOW        "\x1b[33m"
# define RESET        "\x1b[0m"

typedef struct		s_ants
{
	struct s_way	*way;
	int				id;
	int				inact;
}					t_ants;

typedef struct		s_ways
{
	struct s_way	*way;
	int				len;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_way
{
	struct s_rooms	*room;
	struct s_way	*next;
}					t_way;

typedef struct		s_links
{
	struct s_rooms	*room;
	struct s_links	*next;
}					t_links;

typedef	struct		s_rooms
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	int				start;
	int				end;
	int				visited;
	int				inway;
	t_links			*link;
	struct s_rooms	*next;

}					t_rooms;

typedef struct		s_lem_in
{
	t_rooms			*beg_r;
	t_rooms			*cur;
	t_ways			*beg_w;
	int				way_is_est;
	int				error;
	int				color;
	int				way_print;
	int				w_sum;
	int				prev;
	char			*buf;
	int				roo_len;
	int				lefta;
	unsigned int	ants;
}					t_lem_in;

void				init(t_lem_in *p);
t_rooms				*lstrooms(void);
t_links				*lstlinks(void);
t_way				*lstway(void);
t_ways				*lstways(void);
void				add_rooms(t_rooms **alst, t_rooms *new);
void				add_links(t_links **alst, t_links *new);
void				add_ways(t_ways **alst, t_ways *new);
void				lst_start(t_rooms **alst);
void				prepare_ways(t_lem_in *p);
void				manage_errors(int code, t_lem_in *p);
void				check_components(t_lem_in *p);
void				comments(t_lem_in *p, char *trim);
void				ants(t_lem_in *p, char *trim);
void				rooms(t_lem_in *p, char *trim);
void				validate_rooms(t_lem_in *p, char **arr);
int					check_name(t_rooms *beg_r, char *name);
void				print_rooms(t_lem_in *p);
int					links_check(t_lem_in *p, char *trim);
int					check_link_exist(t_rooms *first, t_rooms *second);
void				print_links(t_lem_in *p);
void				add_way(t_ways **bw, t_way *w);
void				del_room(t_way *w);
void				add_room(t_way **w, t_rooms *roo);
void				ft_unvis(t_lem_in *p);
void				manage_ants(t_lem_in *p);
void				next_room(t_lem_in *p, t_ants *ants);
void				mova(t_lem_in *p, t_ants *ants, t_ways *tmp_w);
void				prepare_ways(t_lem_in *p);
t_ways				*find_ways(t_lem_in *p, t_ways *bw, t_rooms *roo);
int					check_ways(t_ways *bw, t_way *w, t_rooms *roo, int lenw);
int					criterias(t_ways *bw, t_way *w, t_rooms *roo, int lenw);
void				print_ways(t_lem_in *p);
void				print_way(t_ways *bw);
void				print_muraveis(t_ants *ants, t_lem_in *p);
void				check_valid(t_lem_in *p);
void				check_end(t_lem_in *p, t_rooms *beg);
void				check_start(t_lem_in *p, t_rooms *beg);
int					link_dash(char *trim);
int					link_name(t_rooms *beg, char **arr);

#endif
