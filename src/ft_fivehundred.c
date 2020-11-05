/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fivehundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:36:03 by hholly            #+#    #+#             */
/*   Updated: 2020/10/05 17:31:06 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_ps	*ft_twosplit(t_ps *list, int len)
{
	int med;

	med = ft_getmed(list, len);
	while (ft_num3(list->listb) < len / 2)
	{
		if (list->lista->n < med)
			ft_dop(list, 'b', 1);
		else
			ft_dor(list, 'a', 1);
	}
	return (list);
}

void	ft_double(t_ps *tmp, int lenb)
{
	int	i;
	int	lena;
	int beg;
	int end;
	int l;

	i = 0;
	while (i++ < lenb)
		ft_dop(tmp, 'b', 1);
	lena = ft_num3(tmp->lista);
	ft_min1(tmp);
	ft_max(tmp);
	l = (tmp->maxa - tmp->mina + 1) / (lena / 17);
	beg = tmp->mina;
	while (tmp->lista)
	{
		end = beg + l;
		if (end > tmp->maxa)
			end = tmp->maxa;
		ft_pusha(tmp, beg, end);
		beg = end + 1;
	}
	while (tmp->listb)
		tmp = ft_pushb(tmp);
}

void	ft_fh(t_ps *list)
{
	int	lena;
	int	lenb;
	int	beg;
	int	end;
	int	l;

	lena = ft_num3(list->lista);
	list = ft_twosplit(list, lena);
	lenb = ft_num3(list->listb);
	ft_minb(list);
	ft_maxb(list);
	l = (list->maxb - list->minb + 1) / (lenb / 17);
	beg = list->minb;
	while (list->listb)
	{
		end = beg + l;
		if (end > list->maxb)
			end = list->maxb;
		ft_pushb1(list, beg, end);
		beg = end + 1;
	}
	ft_double(list, lenb);
}
