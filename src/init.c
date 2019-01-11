/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:43:18 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/24 10:43:19 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	init(t_lem_in *p)
{
	p->ants = 0;
	p->error = 0;
	p->roo_len = 0;
	p->lefta = 0;
	p->w_sum = 0;
	p->way_print = 0;
	p->prev = 0;
	p->color = 0;
	p->beg_r = NULL;
	p->beg_w = NULL;
	p->buf = (char*)malloc(sizeof(char) * 1);
	p->buf[0] = '\0';
	p->cur = p->beg_r;
	p->way_is_est = 0;
}
