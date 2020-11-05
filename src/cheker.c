/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:52:00 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 13:12:36 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_gnl(t_ps *list)
{
	char *line;
	char *s;

	s = "";
	if (!(line = (char*)malloc(sizeof(char) * 4)))
		return ;
	ft_bzero(line, 4);
	while (get_next_line(0, &line))
	{
		if (ft_valid(line))
		{
			s = ft_strjoin(s, line);
			s = ft_strjoin(s, " ");
		}
		else
			return ;
	}
	free(line);
	ft_rule(list, s);
}

void	ft_printok(t_ps *list)
{
	t_p *tmp;
	int a;

	if (list->listb)
	{
		write(1, "KO\n", 3);
		return ;
	}
	tmp = list->lista;
	while (tmp->next)
	{
		a = tmp->n;
		tmp = tmp->next;
		if (a > tmp->n)
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

int		main(int argc, char **argv)
{
	t_ps *list;

	if (argc > 1)
	{
		if (!(list = (t_ps *)malloc(sizeof(t_ps))))
			return (1);
		if (!(list = ft_fill_list(argc, argv, list)))
		{
			ft_clear_list(list);
			return (1);
		}
		ft_gnl(list);
		ft_printok(list);
		ft_clear_list(list);
	}
	return (0);
}
