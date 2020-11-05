/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <hholly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:20:47 by hholly            #+#    #+#             */
/*   Updated: 2020/10/06 16:29:47 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FT_PUSH_SWAP_H
# define PUSH_SWAP_FT_PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_p
{
	int			n;
	int			num;
	struct s_p	*next;
	int			c;
}				t_p;

typedef struct	s_ps
{
	t_p *lista;
	t_p *listb;
	int len;
	int mina;
	int maxa;
	int minb;
	int maxb;
}				t_ps;

int				ft_valid(char *line);
t_p				*ft_add_end(t_p *list, char *b);
void			ft_del(t_p *alst);
t_p				*ft_new(char *n);
void			ft_rule(t_ps *list, char *s);
void			ft_dos(t_ps *lista, char a, int print);
void			ft_dop(t_ps *list, char a, int print);
void			ft_dor(t_ps *list, char a, int print);
void			ft_dorr(t_ps *list, char a, int print);
char			**ft_arg(int ac, char **av, t_ps *list);
t_ps			*ft_fill_list(int argc, char **argv, t_ps *list);
void			ft_sort3(t_ps *list);
void			ft_two(t_ps *list);
void			ft_three(t_ps *list);
void			ft_five(t_ps *list, int len);
int				ft_num3(t_p *lista);
void			ft_minlist(t_ps *list, int len);
int				ft_min1(t_ps *list);
void			ft_hundred(t_ps *list, int len);
void			ft_fh(t_ps *list);
void			ft_max(t_ps *list);
int				ft_minb(t_ps *list);
int				ft_maxb(t_ps *list);
void			ft_pusha(t_ps *list, int beg, int end);
t_ps			*ft_pushb(t_ps *list);
void			ft_pushb1(t_ps *list, int beg, int end);
void			ft_clear_s(char **s);
void			ft_clear_list(t_ps *list);
int				ft_getmed(t_ps *list, int len);
void			ft_countarg(char **box, t_ps *list);
#endif
