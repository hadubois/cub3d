/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:56 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 18:31:17 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (!lst || !(*lst) || !del)
		return ;
	save = (*lst)->next;
	del((*lst)->content);
	ft_lstclear(&save, del);
	free(*lst);
	(*lst) = NULL;
}
