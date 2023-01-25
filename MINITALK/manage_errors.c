/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:47:44 by ajeftani          #+#    #+#             */
/*   Updated: 2023/01/25 15:09:37 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}

void	check_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf("\033[91mNO valid PID.\033[0m\n");
		exit(1);
	}
	if (kill(pid, 0) != 0)
	{
		ft_printf("\033[41mWrong PID\033[0m\n");
		exit(1);
	}
}

void	check_the_end(char *str)
{
	int	isit;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		isit = ft_isdigit(str[i]);
		if (isit == 0)
		{
			ft_printf("\033[91mNO valid PID.\033[0m\n");
			exit(1);
		}
		i++;
	}
}

void	check_the_message(char *str)
{
	if (ft_strlen(str) == 0)
		exit(1);
}
