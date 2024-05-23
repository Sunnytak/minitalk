/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:18 by stak              #+#    #+#             */
/*   Updated: 2024/05/06 16:56:54 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_type(const char check, va_list args, int *cmp)
{
	int	print_length;

	print_length = 0;
	if (check == 'c')
		print_length += ft_printchar(va_arg(args, int), cmp);
	else if (check == 's')
		print_length += ft_printstr(va_arg(args, char *), cmp);
	else if (check == 'p')
		print_length += ft_print_ptr(va_arg(args, void *), cmp);
	else if (check == 'd' || check == 'i' )
		print_length += ft_printnbr(va_arg(args, unsigned int), cmp);
	else if (check == 'u')
		print_length += ft_print_unsigned(va_arg(args, int), cmp);
	else if (check == 'x' || check == 'X')
		print_length += ft_hexconvert(va_arg(args, unsigned int), check, cmp);
	else if (check == '%')
		print_length += ft_printchar('%', cmp);
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_length;
	int		cmp;

	cmp = 1;
	print_length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				break ;
			print_length += check_type(*str, args, &cmp);
		}
		else
			print_length += ft_printchar(*str, &cmp);
		str++;
	}
	va_end(args);
	if (cmp == -1)
		return (-1);
	return (print_length);
}
