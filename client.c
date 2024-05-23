/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:27 by stak              #+#    #+#             */
/*   Updated: 2024/05/23 15:16:49 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	send_string(int pid, const char *str)
{
	while (*str)
	{
		send_bits(pid, *str);
		str++;
	}
	send_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client [PID] [\"MESSAGE\"]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
