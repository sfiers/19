/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:24:08 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 17:05:26 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen(str);
	while (str[i] != c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char*)str + i);
}

/*
**int main(void)
**{
**	const char str0[] = "bateau";
**	int d = 'a';
**	printf("%s\n", ft_strchr(str0, d));
**	const char str[] = "bateau";
**	int c = 'a';
**	printf("%s", strrchr(str, c));
**}
*/
