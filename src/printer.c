/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:37:53 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:37:55 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_muraveis(t_ants *ants, t_lem_in *p)
{
	unsigned int i;

	i = 0;
	while (i < p->ants)
	{
		if (ants[i].inact == 1)
		{
			p->color == 1 ? ft_putstr(" 🐜 ") : ft_putstr(RESET"L");
			p->color == 1 ? ft_putstr(RED) : 0;
			ft_putnbr(i + 1);
			p->color == 1 ? ft_putstr(RESET"-") : ft_putstr("-");
			p->color == 1 ? ft_putstr(GREEN) : 0;
			ft_putstr(ants[i].way->room->name);
			ft_putstr(" ");
			p->color == 1 ? ft_putstr(RESET) : 0;
			if (ants[i].way->room->end == 1)
				ants[i].inact = 2;
		}
		i++;
	}
	ft_putstr("\n");
}

void	print_way(t_ways *bw)
{
	t_way *tmp;

	tmp = bw->way;
	while (tmp->next != NULL)
	{
		if (tmp->room->end == 1)
		{
			ft_putstr(GREEN);
			ft_putstr(tmp->room->name);
			ft_putstr(YELLOW" (end)"RESET);
			break ;
		}
		else if (tmp->room->start == 1)
		{
			ft_putstr(YELLOW"(start) "GREEN);
			ft_putstr(tmp->room->name);
		}
		else
		{
			ft_putstr(tmp->room->name);
		}
		ft_putstr(RESET" -> "GREEN);
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

void	print_ways(t_lem_in *p)
{
	t_ways *tmp;

	tmp = p->beg_w;
	ft_putstr(RED"\nWAYS:\n");
	while (tmp->next != NULL)
	{
		print_way(tmp);
		tmp = tmp->next;
	}
}
