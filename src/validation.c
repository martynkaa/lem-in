/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:09:41 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/20 20:09:42 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int				add_data(t_lem_in *p, char *trim, int *links)
{
	if (ft_strchr(trim, '-') != NULL && p->ants != 0)
	{
		*links = 1;
		check_components(p);
	}
	if (p->ants == 0)
		ants(p, trim);
	else if (trim[0] == '#')
		comments(p, trim);
	else if (!ft_strcmp(trim, ""))
	{
		check_components(p);
		return (1);
	}
	else if (*links == 0)
		rooms(p, trim);
	else
	{
		if (links_check(p, trim) == 1)
			return (1);
	}
	return (0);
}

void			check_valid(t_lem_in *p)
{
	char		*trim;
	int			links;
	char		*line;
	char		*tmp;

	links = 0;
	trim = NULL;
	while (get_next_line(0, &line) > 0)
	{
		tmp = line;
		trim = ft_strtrim(line);
		p->buf = ft_strjoin_freestrs(p->buf, line);
		p->buf = ft_strjoin_freestr1(p->buf, "\n");
		if (add_data(p, trim, &links))
		{
			free(trim);
			break ;
		}
		free(trim);
		trim = NULL;
	}
	if (p->ants == 0)
		manage_errors(3, p);
	if (links == 0)
		manage_errors(10, p);
}
