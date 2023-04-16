/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianschmiedt <christianschmiedt@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:26:42 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/03 17:29:00 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the function ft_lstclear() deletes and frees the node of a linked-list 'lst'
// and frees the given node and every successor that node using the functions
// 'del' and free(3).

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_next;

	if (!del)
		return ;
	while ((*lst))
	{
		temp_next = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp_next;
	}
	return ;
}
