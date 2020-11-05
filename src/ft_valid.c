/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:08:57 by hholly            #+#    #+#             */
/*   Updated: 2020/10/05 14:17:01 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_valid(char *line)
{
	if (ft_strcmp(line, "ra") && ft_strcmp(line, "rb") &&\
		ft_strcmp(line, "rr") && ft_strcmp(line, "sa") &&\
		ft_strcmp(line, "sb") &&\
		ft_strcmp(line, "ss") && ft_strcmp(line, "pa") &&\
		ft_strcmp(line, "pb") && ft_strcmp(line, "rrr") &&\
		ft_strcmp(line, "rra") && \
		ft_strcmp(line, "rrb"))
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	return (1);
}

void	ft_countarg(char **box, t_ps *list)
{
	list->len = 0;
	while (box[list->len])
		list->len++;
}

int		ft_num3(t_p *lista)
{
	int i;
	t_p *tmp;

	tmp = lista;
	i = 0;
	while (tmp)
	{
		tmp->num = i;
		tmp = tmp->next;
		i++;
	}
	return (i);
}
