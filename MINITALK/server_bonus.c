/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 05:09:48 by ajeftani          #+#    #+#             */
/*   Updated: 2023/01/24 00:40:55 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *kra)
{
	static int	convey;
	static int	letter;

	(void)kra;
	if (signal == SIGUSR1)
		letter |= (0x01 << convey);
	convey++;
	if (convey == 8)
	{
		ft_printf("%c", letter);
		convey = 0;
		letter = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	tim;

	(void)av;
	if (ac > 1)
	{
		ft_printf("Error");
		exit(1);
	}
	pid = getpid();
	ft_printf("this is the PID : \033[0;32m%d\033[0m\n", pid);
	ft_printf("\033[43mWaiting for a message...\033[0m\n");
	tim.sa_sigaction = ft_handler;
	sigemptyset(&tim.sa_mask);
	tim.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &tim, NULL);
		sigaction(SIGUSR2, &tim, NULL);
		pause();
	}
	return (0);
}
