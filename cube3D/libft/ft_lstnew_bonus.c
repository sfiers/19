/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:05:26 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/31 14:17:45 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	if (!(ptr = (t_list*)malloc(sizeof(ptr))))
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
