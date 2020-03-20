/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:40 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 12:54:46 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystackm, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char*)haystackm);
	while (haystackm[i] != '\0' && i < len)
	{
		j = 0;
		if (haystackm[i] != needle[j])
			i++;
		else
		{
			while (needle[j] != '\0' && haystackm[i] == needle[j] && i < len)
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)haystackm + i - j);
			i++;
		}
	}
	return (0);
}

/*
** int main(void)
** {
** 	char needle0[] = "dolor";
** 	char haystackm0[] = "lorem ipsum dolor sit amet";
** 	size_t len0 = 0;
** 	printf("%s\n", ft_strnstr(haystackm0, needle0, len0));
** 	char needle[] = "dolor";
** 	char haystackm[] = "lorem ipsum dolor sit amet";
** 	size_t len = 0;
** 	printf("%s", strnstr(haystackm, needle, len));
** }
*/
