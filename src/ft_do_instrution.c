/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_instrution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:46:37 by hholly            #+#    #+#             */
/*   Updated: 2020/09/22 11:56:03 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_dop(t_ps *list, char a, int print)
{
	t_p *tmp;
	t_p *tmp1;

	tmp = list->lista;
	tmp1 = list->listb;
	if (a == 'b' && list->lista)
	{
		list->lista = list->lista->next;
		list->listb = tmp;
		list->listb->next = tmp1;
	}
	else if (list->listb)
	{
		list->listb = list->listb->next;
		list->lista = tmp1;
		list->lista->next = tmp;
	}
	if (print)
	{
		write(1, "p", 1);
		write(1, &a, 1);
		write(1, "\n", 1);
	}
}

void	ft_pr(char a)
{
	write(1, "r", 1);
	write(1, &a, 1);
	write(1, "\n", 1);
}

void	ft_dor(t_ps *lis, char a, int print)
{
	t_p *tmp;
	t_p *head;
	t_p *list;

	list = (a == 'a') ? lis->lista : lis->listb;
	if (list && list->next)
	{
		head = list;
		tmp = list->next;
		while (list->next)
			list = list->next;
		list->next = head;
		list = list->next;
		list->next = NULL;
		list = tmp;
		if (a == 'a')
			lis->lista = list;
		else
			lis->listb = list;
		if (print)
			ft_pr(a);
	}
}

void	ft_printrr(char a)
{
	write(1, "rr", 2);
	write(1, &a, 1);
	write(1, "\n", 1);
}

void	ft_dorr(t_ps *lis, char a, int print)
{
	t_p *tmp;
	t_p *head;
	t_p *end;
	t_p *list;

	list = (a == 'a') ? lis->lista : lis->listb;
	if (list && list->next)
	{
		tmp = list;
		head = list;
		while (tmp->next)
		{
			end = tmp;
			tmp = tmp->next;
		}
		end->next = NULL;
		list = tmp;
		list->next = head;
		if (a == 'a')
			lis->lista = list;
		else
			lis->listb = list;
		if (print)
			ft_printrr(a);
	}
}
