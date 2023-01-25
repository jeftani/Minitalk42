/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 05:11:45 by ajeftani          #+#    #+#             */
/*   Updated: 2023/01/25 15:05:28 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_validate(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\033[0;32mReceived!\033[0;32m\n");
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sign);
}

void	ft_forward(int pid, char letter)
{
	int	convey;

	convey = 0;
	while (convey < 8)
	{
		if ((letter & (0x01 << convey)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		convey++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*current_char;

	i = 0;
	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		return (1);
	}
	else
	{
		current_char = &argv[2][0];
		check_the_end(&argv[1][0]);
		pid = ft_atoi(argv[1]);
		check_pid(pid);
		check_the_message(&argv[2][0]);
		while (*current_char != '\0')
		{
			signal(SIGUSR2, ft_validate);
			ft_forward(pid, *current_char);
			current_char++;
		}
		ft_forward(pid, '\n');
	}
}
