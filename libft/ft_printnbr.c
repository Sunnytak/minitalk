/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:36 by stak              #+#    #+#             */
/*   Updated: 2024/05/06 17:01:16 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n, int *cmp)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_printstr ("-2147483648", cmp);
		return (count);
	}
	else
	{
		if (n < 0)
		{
			count += ft_printchar ('-', cmp);
			n = -n;
		}
		if (n >= 10)
		{
			count += ft_printnbr(n / 10, cmp);
			count += ft_printnbr(n % 10, cmp);
		}
		else
			count += ft_printchar (n + 48, cmp);
	}
	return (count);
}
