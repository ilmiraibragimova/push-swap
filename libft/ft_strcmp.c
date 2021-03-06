/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:38:07 by hholly            #+#    #+#             */
/*   Updated: 2019/09/17 18:17:37 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s11;
	unsigned char *s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (*s11 == *s22 && *s11)
	{
		s11++;
		s22++;
	}
	return ((*s11 - *s22));
}
