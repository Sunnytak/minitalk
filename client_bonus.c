/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:07:01 by stak              #+#    #+#             */
/*   Updated: 2024/05/23 16:50:43 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message not received by server\n");
	if (signal == SIGUSR2)
		ft_printf("Message received by server\n");
}

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
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	pid = atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
