/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:52:12 by stak              #+#    #+#             */
/*   Updated: 2023/11/22 15:14:42 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_count(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	len;
	long int	numb;
	long int	i;
	char		*str;

	len = ft_nb_count(n);
	numb = (long int)n;
	i = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (numb < 0)
	{
		str[0] = '-';
		numb *= -1;
		i = 1;
	}
	while (len > i)
	{
		len--;
		str[len] = '0' + numb % 10;
		numb /= 10;
	}
	return (str);
}
