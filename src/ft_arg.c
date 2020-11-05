/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:06:17 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 15:13:11 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int		ft_is_eq(char **box)
{
	int i;
	int j;

	i = 0;
	while (box[i] != NULL)
	{
		j = i + 1;
		while (box[j] != NULL)
		{
			if (ft_strcmp(box[i], box[j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_is_int(char **box)
{
	int		i;
	int		elem;
	char	*elem1;

	i = -1;
	while (box[++i])
	{
		elem = ft_atoi(box[i]);
		elem1 = ft_itoa(elem);
		if (ft_strcmp(box[i], elem1))
		{
			free(elem1);
			return (0);
		}
		free(elem1);
	}
	return (1);
}

char	*ft_arg_join(int ac, char **av)
{
	char	*s1;
	char	*s2;
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("");
	while (++i < ac)
	{
		s1 = ft_strjoin(s, av[i]);
		ft_strdel(&s);
		s2 = ft_strjoin(s1, " ");
		s = ft_strdup(s2);
		free(s1);
		free(s2);
	}
	s1 = NULL;
	s2 = NULL;
	return (s);
}

char	**ft_arg(int ac, char **av, t_ps *list)
{
	char **box;
	char *s;

	s = ft_arg_join(ac, av);
	box = ft_strsplit(s, ' ');
	ft_strdel(&s);
	if (!(ft_is_eq(box)) || (!ft_is_int(box)))
	{
		write(1, "Error\n", 6);
		ft_clear_s(box);
		exit(1);
	}
	ft_countarg(box, list);
	return (box);
}

t_ps	*ft_fill_list(int argc, char **argv, t_ps *list)
{
	char	**box;
	int		i;

	i = 0;
	if (!(box = ft_arg(argc, argv, list)))
		return (NULL);
	if (!(list->lista = ft_new(box[0])))
		return (NULL);
	list->listb = NULL;
	while (++i < list->len)
		ft_add_end(list->lista, box[i]);
	ft_clear_s(box);
	return (list);
}
