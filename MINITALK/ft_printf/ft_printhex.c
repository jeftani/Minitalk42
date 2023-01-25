/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:25:00 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/11 21:17:49 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexalentgh(unsigned int c)
{
	int	size;

	size = 0;
	if (c == 0)
		size++;
	while (c != 0)
	{
		size++;
		c = c / 16;
	}
	return (size);
}

int	ft_printhex(unsigned int c, char format)
{
	int		i;
	int		lenghofhexa;
	char	*str;

	i = 0;
	lenghofhexa = hexalentgh(c);
	if (c >= 16)
	{
		ft_printhex(c / 16, format);
		ft_printhex(c % 16, format);
	}
	if (format == 'x')
		str = "0123456789abcdef";
	else if (format == 'X')
		str = "0123456789ABCDEF";
	if (c < 16)
	{
		if (format)
			ft_putchar(str[c]);
	}
	return (lenghofhexa);
}
