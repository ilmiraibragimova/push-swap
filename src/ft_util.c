/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:03:51 by hholly            #+#    #+#             */
/*   Updated: 2020/10/05 14:06:11 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_minb(t_ps *list)
{
	int ind;
	t_p *tmp;

	tmp = list->listb;
	list->minb = tmp->n;
	ind = 0;
	while (tmp)
	{
		if (tmp->n < list->minb)
		{
			list->minb = tmp->n;
			ind = tmp->num;
		}
		tmp = tmp->next;
	}
	return (ind);
}

void	ft_pushb1(t_ps *list, int beg, int end)
{
	int i;

	i = ft_num3(list->listb);
	while (i--)
	{
		if (list->listb->n >= beg && list->listb->n <= end)
			ft_dop(list, 'a', 1);
		else
			ft_dor(list, 'b', 1);
	}
}

int		*ft_makeal(t_p *list, int len)
{
	t_p	*tmp;
	int	*s;
	int	i;

	i = 0;
	tmp = list;
	if (!(s = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (tmp)
	{
		s[i++] = tmp->n;
		tmp = tmp->next;
	}
	return (s);
}

int		ft_getmed(t_ps *list, int len)
{
	int	i;
	int	j;
	int	*tmp;
	int	ct;
	int	n1;

	i = 0;
	ct = 0;
	tmp = ft_makeal(list->lista, len);
	while (i < len && ct != len / 2)
	{
		ct = 0;
		j = 0;
		while (j < len)
		{
			if (tmp[j] < tmp[i])
				ct++;
			j++;
		}
		i++;
	}
	n1 = tmp[i - 1];
	free(tmp);
	tmp = NULL;
	return (n1);
}

int		ft_maxb(t_ps *list)
{
	t_p *tmp;
	int ind;

	ind = 0;
	tmp = list->listb;
	list->maxb = tmp->n;
	while (tmp)
	{
		if (tmp->n > list->maxb)
		{
			list->maxb = tmp->n;
			ind = tmp->num;
		}
		tmp = tmp->next;
	}
	return (ind);
}
