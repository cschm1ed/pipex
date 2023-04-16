/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:06 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/16 17:51:53 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print_char() displays a single char, and returns 1.

#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, STDERR_FILENO);
	return (1);
}
