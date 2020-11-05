/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:15:24 by hholly            #+#    #+#             */
/*   Updated: 2020/09/19 16:15:56 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_clear_s(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_strdel(&(s[i]));
	ft_strdel(&(s[i]));
	free(s);
	s = NULL;
}

void	ft_clear_lista(t_p *list)
{
	t_p *al;
	t_p *temp;

	al = list;
	while (al)
	{
		temp = al->next;
		free(al);
		al = temp;
	}
}

void	ft_clear_list(t_ps *list)
{
	ft_clear_lista(list->lista);
	ft_clear_lista(list->listb);
	free(list);
	list = NULL;
}
