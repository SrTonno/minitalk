/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:40:17 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/02 16:25:07 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_content;
	int		i;

	if (!lst || !del || !f)
		return (NULL);
	i = 0;
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		ft_lstadd_back(&new_lst, ft_lstnew(new_content));
		if (!new_lst)
			ft_lstclear(&new_lst, del);
		lst = lst->next;
	}
	return (new_lst);
}
