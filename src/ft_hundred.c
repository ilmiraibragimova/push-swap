/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:51:18 by ilmira            #+#    #+#             */
/*   Updated: 2020/10/05 17:29:22 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int		ft_min1(t_ps *list)
{
	int ind;
	t_p *tmp;

	tmp = list->lista;
	list->mina = tmp->n;
	ind = 0;
	while (tmp)
	{
		if (tmp->n < list->mina)
		{
			list->mina = tmp->n;
			ind = tmp->num;
		}
		tmp = tmp->next;
	}
	return (ind);
}

void	ft_max(t_ps *list)
{
	t_p *tmp;

	tmp = list->lista;
	list->maxa = tmp->n;
	while (tmp)
	{
		if (tmp->n > list->maxa)
			list->maxa = tmp->n;
		tmp = tmp->next;
	}
}

void	ft_pusha(t_ps *list, int beg, int end)
{
	int i;

	i = ft_num3(list->lista);
	while (i--)
	{
		if (list->lista->n >= beg && list->lista->n <= end)
			ft_dop(list, 'b', 1);
		else
			ft_dor(list, 'a', 1);
	}
}

t_ps	*ft_pushb(t_ps *list)
{
	int ind;
	int med;
	int len;
	int i;

	i = -1;
	len = ft_num3(list->listb);
	med = len / 2;
	ind = ft_maxb(list);
	if (ind < med)
		while (ind--)
			ft_dor(list, 'b', 1);
	else
		while (++i < len - ind)
			ft_dorr(list, 'b', 1);
	ft_dop(list, 'a', 1);
	return (list);
}

void	ft_hundred(t_ps *list, int len)
{
	int beg;
	int end;
	int l;
	int k;

	ft_min1(list);
	ft_max(list);
	if (len <= 17)
		k = 1;
	else
		k = 17;
	l = (list->maxa - list->mina + 1) / (len / k);
	beg = list->mina;
	while (list->lista)
	{
		end = beg + l;
		if (end > list->maxa)
			end = list->maxa;
		ft_pusha(list, beg, end);
		beg = end + 1;
	}
	while (list->listb)
		list = ft_pushb(list);
}
