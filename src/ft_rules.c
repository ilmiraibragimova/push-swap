/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:05:13 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 15:03:04 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_dos(t_ps *list, char a, int print)
{
	int		temp;
	t_p		*tmp;
	t_p		*t;

	if (a == 'a')
		t = list->lista;
	else
		t = list->listb;
	if (t && t->next)
	{
		tmp = t;
		temp = t->n;
		tmp = tmp->next;
		t->n = tmp->n;
		tmp->n = temp;
	}
	if (print)
	{
		write(1, "s", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_rule1(char **box, int i, t_ps *list)
{
	if (!(ft_strcmp(box[i], "pa")))
		ft_dop(list, 'a', 0);
	else if (!(ft_strcmp(box[i], "pb")))
		ft_dop(list, 'b', 0);
	else if (!(ft_strcmp(box[i], "rr")))
	{
		ft_dor(list, 'a', 0);
		ft_dor(list, 'b', 0);
	}
	else if (!(ft_strcmp(box[i], "ra")))
		ft_dor(list, 'a', 0);
	else if (!(ft_strcmp(box[i], "rb")))
		ft_dor(list, 'b', 0);
	else if (!(ft_strcmp(box[i], "rrr")))
	{
		ft_dorr(list, 'a', 0);
		ft_dorr(list, 'b', 0);
	}
	else if (!(ft_strcmp(box[i], "rra")))
		ft_dorr(list, 'a', 0);
	else if (!(ft_strcmp(box[i], "rrb")))
		ft_dorr(list, 'b', 0);
}

void	ft_rule(t_ps *list, char *s)
{
	char	**box;
	int		i;

	i = -1;
	box = ft_strsplit(s, ' ');
	while (box[++i])
	{
		if (!(ft_strcmp(box[i], "sa")))
			ft_dos(list, 'a', 0);
		else if (!(ft_strcmp(box[i], "sb")))
			ft_dos(list, 'b', 0);
		else if (!(ft_strcmp(box[i], "ss")))
		{
			ft_dos(list, 'b', 0);
			ft_dos(list, 'a', 0);
		}
		else
			ft_rule1(box, i, list);
	}
	ft_clear_s(box);
}
