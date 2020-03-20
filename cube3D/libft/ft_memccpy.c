/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:46:56 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/22 17:16:45 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst2;
	const unsigned char		*src2;
	size_t					i;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == (unsigned char)c)
			return ((unsigned char*)(dst + i + 1));
		i++;
	}
	return (0);
}

/*
** int main(void)
** {
**	char dst[] = "lal";
**	const char src[] = "elephant";
**	int c = 'p';
**	size_t n = 6;
**	printf("%s", ft_memccpy(dst, src, c, n));
**
**	char dst1[] = "lal";
**	const char src1[] = "elephant";
**	int c2 = 'p';
**	size_t n2 = 4;
**	printf("%s", memccpy(dst1, src1, c2, n2));
** }
*/
