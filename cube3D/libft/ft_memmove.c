/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:53:16 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 16:52:17 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = (unsigned char*)dst;
	src2 = (const unsigned char*)src;
	if (src2 < dst2)
	{
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	}
	else
		ft_memcpy(dst2, src2, len);
	return (dst);
}
/*
** int main(void)
** {
** 	char dst0[] = "elephant";
** 	const char src0[] = "saperlipopette";
** 	size_t n0 = 9;
** 	printf("%s\n", ft_memmove(dst0, src0, n0));
**
** 	char dst[] = "elephant";
** 	const char src[] = "saperlipopette";
** 	size_t n = 9;
** 	printf("%s", memmove(dst, src, n));
** }
*/
