/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:30:37 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:30:38 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			check_name(t_rooms *beg_r, char *name)
{
	t_rooms *beg;

	beg = beg_r;
	while (beg && beg->name)
	{
		if (ft_strcmp(beg->name, name) == 0)
			return (0);
		beg = beg->next;
	}
	return (1);
}

void		validate_rooms(t_lem_in *p, char **arr)
{
	int		i;
	int		j;
	t_rooms *beg;

	i = 0;
	j = 0;
	beg = p->beg_r;
	while (arr[++i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (ft_isdigit(arr[i][j]))
				j++;
			else
				manage_errors(7, p);
		}
		i > 0 && j > 10 ? manage_errors(6, p) : 0;
	}
	while (beg != NULL)
	{
		(int)beg->x == ft_atoi(arr[1]) && (int)beg->y == ft_atoi(arr[2]) ?
		manage_errors(15, p) : 0;
		beg = beg->next;
	}
}

void		rooms(t_lem_in *p, char *trim)
{
	int		i;
	char	**arr;

	i = 1;
	p->cur == NULL ? p->cur = lstrooms() : 0;
	trim[i] == 'L' ? manage_errors(4, p) : 0;
	arr = ft_strsplit(trim, ' ');
	ft_arr_size(arr) != 3 ? manage_errors(5, p) : 0;
	(check_name(p->beg_r, arr[0]) == 1) ? p->cur->name = ft_strdup(arr[0]) :
	manage_errors(9, p);
	validate_rooms(p, arr);
	p->cur->x = ft_atoi(arr[1]);
	p->cur->y = ft_atoi(arr[2]);
	p->cur->x > 2147483647 || p->cur->y > 2147483647 ? manage_errors(6, p) : 0;
	add_rooms(&p->beg_r, p->cur);
	p->roo_len += 1;
	p->cur = p->cur->next;
	ft_free_mass(arr, 2);
}
