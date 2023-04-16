/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_itohex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:01:01 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/16 17:52:30 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The print_itohex_upper() function takes an unsigned int 'n' and displays
// its hexadecimal representation in upper-case.
// The print_itohex_upper() function returns the amount of characters
// it displayed.

#include "ft_printf.h"

static void	writenbr_recursively(unsigned int n)
{
	int	digit;

	if (n == 0)
		return ;
	else
		writenbr_recursively(n / 16);
	digit = n % 16;
	if (digit > 9)
		ft_putchar_fd('A' + digit - 10, STDERR_FILENO);
	else
		ft_putchar_fd(digit + '0', STDERR_FILENO);
	return ;
}

static int	get_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i ++;
	}
	return (i);
}

int	print_itohex_upper(unsigned int n)
{
	if (n == 0)
	{
		ft_putchar_fd('0', STDERR_FILENO);
		return (1);
	}
	writenbr_recursively(n);
	return (get_len(n));
}
