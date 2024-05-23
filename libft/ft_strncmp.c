/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:12:21 by stak              #+#    #+#             */
/*   Updated: 2023/11/06 17:04:44 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	i = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (i < n && (uc1[i] != 0 || uc2[i] != 0))
	{
		if (uc1[i] > uc2[i])
		{
			return (uc1[i] - uc2[i]);
		}
		else if (uc1[i] < uc2[i])
		{
			return (uc1[i] - uc2[i]);
		}
		i++;
	}
	return (0);
}
