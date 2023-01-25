/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:02:02 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/11 21:18:23 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int numbers)
{
	int	i;

	i = 0;
	if (numbers == 0)
		return (1);
	while (numbers != 0)
	{
		i++;
		numbers /= 10;
	}
	return (i);
}

int	ft_putunsnumber(unsigned int c)
{
	int	len;

	len = ft_len(c);
	if (c >= 10)
	{
		ft_putunsnumber(c / 10);
		ft_putunsnumber(c % 10);
	}
	else if (c < 10)
	{
		ft_putchar(c + '0');
	}
	return (len);
}
