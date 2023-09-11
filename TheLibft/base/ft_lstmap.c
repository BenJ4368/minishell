/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:32:24 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/29 15:07:37 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*top;
	t_list	*new;
	void	*temp;

	new = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		top = ft_lstnew(temp);
		if (!top)
		{
			free(temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, top);
		lst = lst->next;
	}
	return (new);
}
