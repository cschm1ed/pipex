/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianschmiedt <christianschmiedt@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:05 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/03 17:31:23 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function ft_lstsize() returns the size of the linked-list 'lst'.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		i ++;
	}
	return (i);
}
