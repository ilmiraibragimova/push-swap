/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:57:14 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 16:18:03 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int		ft_issort(t_ps *list)
{
	t_p *tmp;
	int a;

	if (list->listb)
		return (0);
	tmp = list->lista;
	while (tmp->next)
	{
		a = tmp->n;
		tmp = tmp->next;
		if (a > tmp->n)
			return (0);
	}
	return (1);
}

void	ft_sort3(t_ps *list)
{
	int len;

	if (ft_issort(list))
		return ;
	len = ft_num3(list->lista);
	if (len == 2)
		ft_two(list);
	else if (len == 3)
		ft_three(list);
	else if (len == 5 || len == 4)
		ft_five(list, len);
	else if (len > 5 && len < 200)
		ft_hundred(list, len);
	else if (len >= 200)
		ft_fh(list);
}
