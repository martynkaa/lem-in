/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:31:50 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/24 09:31:52 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void			parse_flags(t_lem_in *p, char **argv)
{
	int			i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
			p->color = 1;
		else if (ft_strcmp(argv[i], "-w") == 0)
			p->way_print = 1;
		else if (ft_strcmp(argv[i], "-e") == 0)
			p->error = 1;
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_lem_in	p;
	int			links;

	links = 0;
	init(&p);
	parse_flags(&p, argv);
	(void)argc;
	check_valid(&p);
	ft_putstr(p.buf);
	prepare_ways(&p);
	return (0);
}
