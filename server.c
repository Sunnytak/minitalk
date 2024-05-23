/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:22 by stak              #+#    #+#             */
/*   Updated: 2024/05/23 18:19:30 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static char	current_char;
	static char	message[MAX_MESSAGE_LENGTH];
	static int	char_index;

	if (signal == SIGUSR1)
		current_char |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (current_char == '\0')
		{
			message[char_index] = '\0';
			ft_printf("%s\n", message);
			char_index = 0;
		}
		else
		{
			message[char_index++] = current_char;
		}
		bit = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID [%d]\n", pid);
	ft_printf("Waiting for a message...\n");
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
