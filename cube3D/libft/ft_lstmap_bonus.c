/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:16:51 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/30 21:52:14 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*temp;

	lstnew = f(lst);
	temp = lstnew;
	if (!lst || !del)
		return NULL;
	if (!(lstnew= (t_list*)malloc(sizeof(lstnew))))
		return(NULL);
	while (temp)
	{
		f(lst);
		temp = lst->next;
		lst = lst->next;
		del(lst->content);
		free(lst);
	}
	return(lstnew);
}