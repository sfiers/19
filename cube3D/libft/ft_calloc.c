/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:47:03 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 16:33:48 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (count * size))))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
** int main(void)
** {
** 	size_t count0 = 3;
** 	size_t size0 = 4;
** 	ft_calloc(count0, size0);
** 	//printf("%s", ft_calloc(count0, size0));
** 	size_t count1 = 3;
** 	size_t size1 = 4;
** 	//printf("%s", calloc(count1, size1));
** 	//printf("")
** }
*/
