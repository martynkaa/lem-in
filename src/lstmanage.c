/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstrooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 09:38:37 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/25 09:38:38 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_rooms		*lstrooms(void)
{
	struct s_rooms *new;

	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	else
	{
		new->name = NULL;
		new->x = 0;
		new->y = 0;
		new->start = 0;
		new->end = 0;
		new->visited = 0;
		new->inway = 0;
		new->link = NULL;
	}
	new->next = NULL;
	return (new);
}

t_links		*lstlinks(void)
{
	struct s_links *new;

	if (!(new = (t_links *)malloc(sizeof(t_links))))
		return (NULL);
	new->room = NULL;
	new->next = NULL;
	return (new);
}

t_ways		*lstways(void)
{
	struct s_ways *new;

	if (!(new = (t_ways *)malloc(sizeof(t_ways))))
		return (NULL);
	new->way = NULL;
	new->len = 0;
	new->next = NULL;
	return (new);
}

t_way		*lstway(void)
{
	struct s_way *new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return (NULL);
	new->room = NULL;
	new->next = NULL;
	return (new);
}

void		lst_start(t_rooms **alst)
{
	t_rooms *tmp;
	t_rooms *prev;
	t_rooms *start;

	start = NULL;
	tmp = *alst;
	prev = tmp;
	if (alst && *alst)
	{
		while (tmp != NULL)
		{
			if (tmp->start == 1)
			{
				start = tmp;
				if (start == *alst)
					return ;
				prev->next = start->next;
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		start->next = *alst;
		*alst = start;
	}
}
