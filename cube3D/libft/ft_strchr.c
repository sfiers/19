/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:46 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 17:02:56 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char*)s + i);
}
/*
**int main(void)
**{
**	const char str0[] = "bateau";
**	int d = '0';
**	printf("%s\n", ft_strchr(str0, d));
**
**	const char str[] = "bateau";
**	int c = '0';
**	printf("%s", strchr(str, c));
**}
*/
