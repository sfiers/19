/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:52:54 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 16:43:52 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;
	size_t					i;

	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
** int main(void)
** {
** 	char str1[] = "atoms\0\0\0\0";
** 	char str2[] = "atoms\0abc";
** 	size_t n = 8;
** 	char str01[] = "atoms\0\0\0\0";
** 	char str02[] = "atoms\0abc";
** 	size_t n0 = 8;
**
** 	int i1 = ((simple_memcmp(str01, str02, n0) > 0) ?
**	 1 : ((simple_memcmp(str01, str02, n0) < 0) ? -1 : 0));
** 	int i2 = ((ft_memcmp(str1, str2, n) > 0) ?
**	 1 : ((ft_memcmp(str1, str2, n) < 0) ? -1 : 0));
** 		if (i1 == i2)
** 					exit(TEST_SUCCESS);
** 			exit(TEST_FAILED);
** 	printf("%d\n",ft_memcmp(str1, str2, n));
** 	printf("%d",memcmp(str01, str02, n0));
** }
*/
