/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:41:37 by xriera-c          #+#    #+#             */
/*   Updated: 2023/11/06 13:12:47 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nextnode;

	if (del && lst)
	{
		node = *lst;
		while (node)
		{
			nextnode = node->next;
			del(node->content);
			free(node);
			node = nextnode;
		}
		*lst = NULL;
	}
}
