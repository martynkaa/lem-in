/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:39:26 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:39:27 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		mova(t_lem_in *p, t_ants *ants, t_ways *tmp_w)
{
	int		i;

	i = -1;
	while (tmp_w->next != NULL && p->lefta > 0)
	{
		p->w_sum += tmp_w->len;
		if (p->lefta > 0 &&
			((p->lefta > p->w_sum - tmp_w->len && p->lefta > tmp_w->len) ||
				(p->w_sum - tmp_w->len == p->prev) ||
				(p->w_sum == tmp_w->len)))
		{
			while (++i < (int)p->ants)
			{
				if (ants[i].inact == 0)
				{
					ants[i].way = tmp_w->way->next;
					ants[i].inact = 1;
					p->lefta--;
					break ;
				}
			}
		}
		p->prev = tmp_w->len;
		tmp_w = tmp_w->next;
	}
}

void		next_room(t_lem_in *p, t_ants *ants)
{
	unsigned int i;

	i = 0;
	while (i < p->ants)
	{
		if (ants[i].inact == 1)
			ants[i].way = ants[i].way->next;
		i++;
	}
}

void		shortest_way(t_lem_in *p, t_ants *ants)
{
	unsigned int i;

	i = 0;
	while (i < p->ants)
	{
		ants[i].id = i;
		ants[i].inact = 1;
		ants[i].way = p->beg_w->way->next;
		i++;
	}
	print_muraveis(ants, p);
}

void		manage_ants(t_lem_in *p)
{
	t_ants	*ants;
	t_ways	*tmp_w;
	int		i;

	i = -1;
	ants = (t_ants*)malloc(sizeof(t_ants) * p->ants);
	while (++i < (int)p->ants)
	{
		ants[i].id = i;
		ants[i].inact = 0;
		ants[i].way = NULL;
	}
	p->lefta = p->ants;
	ft_putstr("\n");
	if (p->beg_w->len == 1)
		shortest_way(p, ants);
	while (ants[p->ants - 1].inact != 2)
	{
		p->w_sum = 0;
		tmp_w = p->beg_w;
		next_room(p, ants);
		mova(p, ants, tmp_w);
		print_muraveis(ants, p);
	}
	free(ants);
}
