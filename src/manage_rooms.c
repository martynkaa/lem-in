/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:38:54 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:38:56 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	add_way(t_ways **bw, t_way *w)
{
	t_way *tmp;

	(*bw)->way = w;
	tmp = w;
	while (tmp->next != NULL)
	{
		if (tmp->room->start == 0 && tmp->room->end == 0)
			tmp->room->inway = 1;
		tmp = tmp->next;
	}
	(*bw)->next = lstways();
	(*bw) = (*bw)->next;
}

void	del_room(t_way *w)
{
	t_way *tmp;
	t_way *prev;

	tmp = w;
	prev = w;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			free(tmp);
			prev->next = NULL;
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	add_room(t_way **w, t_rooms *roo)
{
	roo->visited = 1;
	(*w)->room = roo;
	(*w)->next = lstway();
	(*w) = (*w)->next;
}

void	ft_unvis(t_lem_in *p)
{
	t_rooms *tmp;

	tmp = p->beg_r;
	while (tmp != NULL)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}
