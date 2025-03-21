/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:13:47 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/13 15:14:19 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*save;

	output = NULL;
	while (lst)
	{
		save = ft_lstnew(f(lst->content));
		if (!save)
			return (ft_lstclear(&output, del), NULL);
		ft_lstadd_back(&output, save);
		lst = lst->next;
	}
	return (output);
}
