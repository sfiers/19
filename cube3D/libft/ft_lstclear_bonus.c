/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:54:29 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/30 22:32:34 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*list;

	if (!lst || !*lst)
		return ;
	list = *lst;
	temp = NULL;
	while (list)
	{
		if (list->next)
			temp = list->next;
		else
			temp = NULL;
		ft_lstdelone(list, (del));
		list = temp;
	}
	*lst = NULL;
}
