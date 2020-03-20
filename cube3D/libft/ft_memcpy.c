/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:02:57 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 16:48:16 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dst2;
	const unsigned char		*src2;
	unsigned int			i;

	dst2 = (unsigned char*)dst;
	src2 = (const unsigned char*)src;
	i = 0;
	if (dst2 == 0 && src2 == 0)
		return (0);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

/*
**int main(void)
**{
**	fprintf(stderr,"%s", memcpy(((void *)0), ((void *)0), 3));
**	char dst1[] = "";
**	char src1[] = "lal";
**	size_t n1 = 4;
**	fprintf(stderr,"%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
**
**	// char dst[] = "coucou";
**	// char src[] = "lal";
**	// size_t n = 4;
**}
*/
