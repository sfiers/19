/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:18:50 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/30 22:50:27 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s2;
	size_t	i;

	s2 = (char*)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}

/*
**int main(void)
**{
**  char *src = "/|\x12\xff\x09\x42\2002\42|\\";
**  int size = 10;
**  int c = '\200';
**  printf("%s\n",ft_memchr(src, c, size));
**
**  char *src2 = "/|\x12\xff\x09\x42\2002\42|\\";
**  int size2 = 10;
**  int c2 = '\200';
**  printf("%s",memchr(src2, c2, size2));
**}
*/
