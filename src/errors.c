/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:33:48 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/08/19 10:33:49 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	manage_errors(int code, t_lem_in *p)
{
	ft_putstr("ERROR");
	if (p->error == 1)
	{
		code == 1 ? ft_putstr(": non-valid format of ants") : 0;
		code == 2 ? ft_putstr(": oh! there are too much ants! help!") : 0;
		code == 3 ? ft_putstr(": no ants.. no sense to find a way!") : 0;
		code == 4 ? ft_putstr(": rooms can't start with 'L'!") : 0;
		code == 5 ? ft_putstr(": wrong room format!") : 0;
		code == 6 ? ft_putstr(": strange coordinates.. maybe lower?") : 0;
		code == 7 ? ft_putstr(": check coords format, there is a mistake!") : 0;
		code == 8 ? ft_putstr(": are you think i understand this?") : 0;
		code == 9 ? ft_putstr(": the same room'name may cause problems..") : 0;
		code == 10 ? ft_putstr(": no links!") : 0;
		code == 11 ? ft_putstr(": name doesn't exists! mnogohodovochka?") : 0;
		code == 12 ? ft_putstr(": i've already seen this command.. hm..") : 0;
		code == 13 ? ft_putstr(": start .. where are you?") : 0;
		code == 14 ? ft_putstr(": end .. where are you?") : 0;
		code == 15 ? ft_putstr(": same coord? no it won't work!") : 0;
		code == 16 ? ft_putstr(": sorry, but links format is very strict") : 0;
	}
	ft_putstr("\n");
	(void)p;
	exit(0);
}
