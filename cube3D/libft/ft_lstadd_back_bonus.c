/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:12:32 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/30 21:18:52 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;
	int		i;

	i = 0;
	if (*alst == 0)
		*alst = new;
	if (alst && new)
	{
		list = *alst;
		while (i < ft_lstsize(*alst) - 1)
		{
			list = list->next;
			i++;
		}
		list->next = new;
		new->next = 0;
	}
}
