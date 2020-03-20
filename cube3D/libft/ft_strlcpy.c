/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:15:00 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/22 15:03:06 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 0 && src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
** int main(void)
** {
**	char dst0[] = "rectangle";
**	char src0[] = "lol";
** 	size_t n0 = 1;
**	printf("%lu\n", ft_strlcpy(dst0, src0, n0));
** 	ft_strlcpy(dst0, src0, n0);
** 	printf("dst = %s\n", dst0);
**
** 	char dst[] = "rectangle";
**	char src[] = "lol";
** 	size_t n = 1;
** 	printf("%lu\n", strlcpy(dst, src, n));
** 	strlcpy(dst, src, n);
** 	printf("dst = %s", dst);
** }
*/
