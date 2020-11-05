/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:43:00 by hholly            #+#    #+#             */
/*   Updated: 2020/09/19 16:45:16 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_del(t_p *alst)
{
	t_p *al;
	t_p *temp;

	al = alst;
	while (al)
	{
		temp = al->next;
		free(al);
		al = temp;
	}
	alst = NULL;
}

t_p		*ft_new(char *n)
{
	t_p *listnew;

	if (!(listnew = (t_p*)malloc(sizeof(t_p))))
		return (NULL);
	listnew->n = ft_atoi(n);
	listnew->next = NULL;
	return (listnew);
}

t_p		*ft_add_end(t_p *list, char *b)
{
	t_p *tmp;
	t_p *new;

	tmp = list;
	if (!(new = (t_p*)malloc(sizeof(t_p))))
	{
		ft_del(list);
		return (NULL);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	tmp = tmp->next;
	tmp->n = ft_atoi(b);
	tmp->next = NULL;
	return (list);
}
