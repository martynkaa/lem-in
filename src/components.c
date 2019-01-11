/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:32:50 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:32:51 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		ants(t_lem_in *p, char *trim)
{
	int		i;

	i = 0;
	while (trim[i] != '\0')
	{
		if (ft_isdigit(trim[i]))
			i++;
		else
			manage_errors(1, p);
	}
	i > 10 ? manage_errors(2, p) : 0;
	p->ants = ft_atoi(trim);
	p->ants > 2147483647 ? manage_errors(2, p) : 0;
	p->ants == 0 ? manage_errors(3, p) : 0;
}

void		check_start(t_lem_in *p, t_rooms *beg)
{
	while (beg != NULL)
	{
		beg->start == 1 ? manage_errors(12, p) : 0;
		beg = beg->next;
	}
	p->cur->start == 1 ? manage_errors(12, p) : 0;
	p->cur->end == 1 ? manage_errors(8, p) : 0;
	p->cur->start = 1;
}

void		check_end(t_lem_in *p, t_rooms *beg)
{
	while (beg != NULL)
	{
		beg->end == 1 ? manage_errors(12, p) : 0;
		beg = beg->next;
	}
	p->cur->end == 1 ? manage_errors(12, p) : 0;
	p->cur->start == 1 ? manage_errors(8, p) : 0;
	p->cur->end = 1;
}

void		comments(t_lem_in *p, char *trim)
{
	int		i;
	t_rooms *beg;

	i = 1;
	if (trim[i++] == '#')
	{
		p->cur == NULL ? p->cur = lstrooms() : 0;
		beg = p->beg_r;
		if (ft_strcmp("start", trim + i) == 0)
			check_start(p, beg);
		else if (ft_strcmp("end", trim + i) == 0)
			check_end(p, beg);
	}
}

void		check_components(t_lem_in *p)
{
	t_rooms *beg;
	int		st;
	int		en;

	st = 0;
	en = 0;
	beg = p->beg_r;
	while (beg != NULL)
	{
		beg->start == 1 ? st = 1 : 0;
		beg->end == 1 ? en = 1 : 0;
		beg = beg->next;
	}
	st == 0 ? manage_errors(13, p) : 0;
	en == 0 ? manage_errors(14, p) : 0;
}
