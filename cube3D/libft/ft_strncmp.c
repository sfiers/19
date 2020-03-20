/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:41:48 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 17:06:47 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

/*
**int main(void)
**{
**	const char s01[] = "ha";
**	const char s02[] = "h";
**	size_t n0 = 3;
**	printf("%d\n", ft_strncmp(s01, s02, n0));
**	const char s1[] = "ha";
**	const char s2[] = "h";
**	size_t n = 3;
**	printf("%d", strncmp(s1, s2, n));
**}
*/
