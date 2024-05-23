/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:46:21 by stak              #+#    #+#             */
/*   Updated: 2024/05/06 17:01:25 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n, int *cmp)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printnbr(n / 10, cmp);
		count += ft_printnbr(n % 10, cmp);
	}
	else
		count += ft_printchar (n + 48, cmp);
	return (count);
}
