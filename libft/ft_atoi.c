/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:49:13 by stak              #+#    #+#             */
/*   Updated: 2023/11/22 14:06:29 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long int i, long int check, long int sign)
{
	if (i > check && sign < 0)
		return (0);
	if (i < check && sign > 0)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long		sign;
	long		check;
	int			over;

	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = i;
		i = i * 10 + sign * (*str - '0');
		over = check_overflow(i, check, sign);
		if (over != 1)
			return (over);
		str++;
	}
	return (i);
}
