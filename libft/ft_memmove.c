/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:30:08 by stak              #+#    #+#             */
/*   Updated: 2023/11/21 16:37:04 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstptr;
	const unsigned char	*srcptr;

	dstptr = dst;
	srcptr = src;
	if (src == '\0' && dst == '\0')
	{
		return (0);
	}
	if (dstptr < srcptr)
	{
		while (len --)
		{
			*dstptr++ = *srcptr++;
		}
	}
	else
	{
		while (len --)
		{
			dstptr[len] = srcptr[len];
		}
	}
	return (dst);
}
