/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:23:59 by ajeftani          #+#    #+#             */
/*   Updated: 2022/11/11 21:17:42 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *symboll, ...);
int	ft_printhex(unsigned int c, char format);
int	printthapointer(unsigned long long c, char format);
int	ft_putchar(int c);
int	ft_putnbr(int c);
int	ft_printstr(char *s);
int	ft_putunsnumber(unsigned int c);

#endif
