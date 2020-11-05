/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:02:29 by hholly            #+#    #+#             */
/*   Updated: 2020/10/05 13:03:59 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ps *list;

	if (argc > 1)
	{
		if (!(list = (t_ps *)malloc(sizeof(t_ps))))
			return (1);
		if (!(list = ft_fill_list(argc, argv, list)))
		{
			ft_clear_list(list);
			return (1);
		}
		ft_sort3(list);
		ft_clear_list(list);
	}
}
