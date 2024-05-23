/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:16:29 by stak              #+#    #+#             */
/*   Updated: 2023/11/22 14:57:07 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	if (s1 == '\0' || s2 == '\0')
	{
		return (0);
	}
	s1_len = (ft_strlen(s1));
	s2_len = (ft_strlen(s2));
	result = (char *)malloc(s1_len + s2_len + 1);
	while (result == '\0')
	{
		return (0);
	}
	ft_memcpy (result, s1, s1_len);
	ft_memcpy (result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}
