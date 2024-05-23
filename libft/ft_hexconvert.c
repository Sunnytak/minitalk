/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:24:04 by stak              #+#    #+#             */
/*   Updated: 2024/05/06 17:00:47 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexconvert(unsigned long long int n, const char check, int *cmp)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_hexconvert(n / 16, check, cmp);
		n = n % 16;
	}
	if (n >= 10)
	{
		if (check == 'x')
			count += ft_printchar(n - 10 + 'a', cmp);
		if (check == 'X')
			count += ft_printchar(n - 10 + 'A', cmp);
	}
	else
	{
		if (n <= 9)
			count += ft_printchar (n + 48, cmp);
	}
	return (count);
}
