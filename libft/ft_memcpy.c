/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@stuent.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:32:06 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/17 08:31:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			x;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	x = 0;
	if (n <= 0 || s1 == s2)
		return (str1);
	while (x < n)
	{
		s1[x] = s2[x];
		x++;
	}
	return (str1);
}
