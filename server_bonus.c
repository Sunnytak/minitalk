/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:47:32 by stak              #+#    #+#             */
/*   Updated: 2024/05/23 18:19:58 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static char	current_char;
	static char	message[MAX_MESSAGE_LENGTH];
	static int	char_index;

	(void)s;
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
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	pid = getpid();
	ft_printf("Welcome To Sunny's Server!\n");
	ft_printf("The PID: [%d]\n", pid);
	ft_printf("Waiting for a message...\n");
	sig.sa_sigaction = ft_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
