/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:43:56 by stak              #+#    #+#             */
/*   Updated: 2023/11/03 15:36:32 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b;
	unsigned char	*c;

	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (n > 0)
	{
		if (*b != *c)
			return (*b - *c);
		n--;
		b++;
		c++;
	}
	return (0);
}
