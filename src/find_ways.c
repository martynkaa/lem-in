/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:54:35 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/04 16:54:35 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			criterias(t_ways *bw, t_way *w, t_rooms *roo, int lenw)
{
	if (roo->end == 1)
	{
		if (bw->len > lenw || bw->len < lenw)
			return (0);
		add_room(&w, roo);
		free(w);
		w = NULL;
		return (1);
	}
	if (roo->visited == 1 || roo->inway == 1 || bw->len > lenw)
		return (0);
	return (2);
}

int			check_ways(t_ways *bw, t_way *w, t_rooms *roo, int lenw)
{
	t_links *lks;

	lks = NULL;
	if (criterias(bw, w, roo, lenw) == 0)
		return (0);
	else if (criterias(bw, w, roo, lenw) == 1)
		return (1);
	else
	{
		add_room(&w, roo);
		bw->len++;
	}
	lks = roo->link;
	while (lks != NULL)
	{
		if (check_ways(bw, w, lks->room, lenw) == 1)
			return (1);
		lks = lks->next;
	}
	del_room(bw->way);
	bw->len--;
	return (0);
}

t_ways		*find_ways(t_lem_in *p, t_ways *bw, t_rooms *roo)
{
	t_way	*w;
	int		lenw;

	lenw = 1;
	w = bw->way;
	while (lenw < p->roo_len)
	{
		if (check_ways(bw, w, roo, lenw) == 1)
		{
			p->way_is_est = 1;
			add_way(&bw, w);
			if (lenw == 1)
				break ;
			bw->way = lstway();
			bw->way->room = p->beg_r;
			w = bw->way;
		}
		else
		{
			bw->len = 0;
			lenw++;
		}
		ft_unvis(p);
	}
	return (bw);
}

void		prepare_ways(t_lem_in *p)
{
	t_ways	*beg_w;
	t_ways	*bw;
	t_way	*way;
	t_rooms	*roo;

	beg_w = lstways();
	p->beg_w = beg_w;
	way = lstway();
	lst_start(&p->beg_r);
	beg_w->way = way;
	roo = p->beg_r;
	bw = beg_w;
	bw = find_ways(p, bw, roo);
	if (p->way_is_est == 1)
	{
		if (p->way_print == 1)
			print_ways(p);
		manage_ants(p);
	}
	else
		ft_putstr("No link with start and end!");
}
