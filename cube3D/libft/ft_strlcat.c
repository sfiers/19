/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:01:11 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 12:07:06 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	if (size > len_dst)
	{
		while (src[i] != '\0' && (len_dst + i) < size - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	else if (size < ft_strlen(dst))
		len_dst = size;
	return (ft_strlen(src) + len_dst);
}

/*
** int main(void)
** {
**
**	char src0[] = "rectangle";
**	char dst0[] = "lolifo";
**	size_t n0 = 2;
**	printf("%lu\n", ft_strlcat(dst0, src0, n0));
**	ft_strlcat(dst0, src0, n0);
**	printf("dst = %s\n", dst0);
**	printf("src = %s\n\n", src0);
**
**	char src[] = "rectangle";
**	char dst[] = "lolifo";
**	size_t n = 2;
**	printf("%lu\n", strlcat(dst, src, n));
**	strlcat(dst, src, n);
**	printf("dst = %s\n", dst);
**	printf("src = %s\n", src);
** }
*/
