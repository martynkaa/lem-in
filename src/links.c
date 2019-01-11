/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:31:39 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:31:41 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			check_link_exist(t_rooms *first, t_rooms *second)
{
	t_links *beg_f;
	t_links *beg_s;

	beg_f = first->link;
	beg_s = second->link;
	while (beg_f && beg_f->room)
	{
		if (ft_strcmp(beg_f->room->name, second->name) == 0)
			return (0);
		beg_f = beg_f->next;
	}
	while (beg_s && beg_s->room)
	{
		if (ft_strcmp(beg_s->room->name, first->name) == 0)
			return (0);
		beg_s = beg_s->next;
	}
	beg_f = lstlinks();
	beg_s = lstlinks();
	beg_f->room = second;
	beg_s->room = first;
	add_links(&first->link, beg_f);
	add_links(&second->link, beg_s);
	return (0);
}

int			link_dash(char *trim)
{
	int		i;
	int		dash;

	i = 0;
	dash = 0;
	while (trim[i] != '\0')
	{
		if (trim[i] == '-')
			dash++;
		i++;
	}
	if (dash > 1)
		return (1);
	return (0);
}

int			link_name(t_rooms *beg, char **arr)
{
	t_rooms *first;
	t_rooms *second;

	first = NULL;
	second = NULL;
	while (beg && beg->name)
	{
		if (ft_strcmp(beg->name, arr[0]) == 0)
			first = beg;
		if (ft_strcmp(beg->name, arr[1]) == 0)
			second = beg;
		beg = beg->next;
	}
	if (first == NULL || second == NULL)
		return (1);
	if (check_link_exist(first, second) == 1)
		return (1);
	return (0);
}

int			links_check(t_lem_in *p, char *trim)
{
	char	**arr;
	t_rooms *beg;

	beg = p->beg_r;
	if (link_dash(trim) == 1)
		return (1);
	arr = ft_strsplit(trim, '-');
	if (arr[2] != NULL)
		return (1);
	if (link_name(beg, arr) == 1)
		return (1);
	ft_free_mass(arr, 1);
	return (0);
}
