/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:01:23 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 15:03:04 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_two(t_ps *list)
{
	if (list->lista->n > list->lista->next->n)
		ft_dos(list, 'a', 1);
}

void	ft_else(int n1, int n2, int n3, t_ps *list)
{
	if (n1 > n2 && n1 > n3 && n2 < n3)
		ft_dor(list, 'a', 1);
	if (n1 < n2 && n2 > n1 && n1 > n3)
		ft_dorr(list, 'a', 1);
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		ft_dos(list, 'a', 1);
		ft_dor(list, 'a', 1);
	}
}

void	ft_three(t_ps *list)
{
	int n1;
	int n2;
	int n3;

	n1 = list->lista->n;
	n2 = list->lista->next->n;
	n3 = list->lista->next->next->n;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_dos(list, 'a', 1);
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ft_dos(list, 'a', 1);
		ft_dorr(list, 'a', 1);
	}
	ft_else(n1, n2, n3, list);
}

void	ft_minlist(t_ps *list, int len)
{
	int ind;

	ind = ft_min1(list);
	if (ind < len / 2)
		while (ind--)
			ft_dor(list, 'a', 1);
	else
		while (ind++ < len)
			ft_dorr(list, 'a', 1);
}

void	ft_five(t_ps *list, int len)
{
	int i;

	i = -1;
	while (++i < len - 3)
	{
		len = ft_num3(list->lista);
		ft_minlist(list, len);
		ft_dop(list, 'b', 1);
	}
	ft_three(list);
	while (list->listb)
		ft_dop(list, 'a', 1);
}
