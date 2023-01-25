/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:08:23 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/11 21:24:26 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countlen(char *s)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

int	ft_printstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_countlen(s);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (len);
}
