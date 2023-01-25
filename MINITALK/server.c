/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:33:27 by ajeftani          #+#    #+#             */
/*   Updated: 2023/01/23 18:10:46 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_handler(int signal)
{
	static int	convey;
	static int	letter;

	if (signal == SIGUSR1)
		letter |= (0x01 << convey);
	convey++;
	if (convey == 8)
	{
		ft_printf("%c", letter);
		convey = 0;
		letter = 0;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	(void)av;
	if (ac > 1)
	{
		ft_printf("Error");
		exit(1);
	}
	pid = getpid();
	ft_printf("this is the PID : \033[0;32m%d\033[0m\n", pid);
	ft_printf("\033[43mWaiting for a message...\033[0m\n");
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
