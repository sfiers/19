/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:44 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 17:03:15 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	i;
	int				j;

	if (s1 == NULL || s2 == NULL || (!(dst = (char*)ft_calloc(sizeof(*dst),
			(ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			dst[i] = s2[j];
			j++;
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

/*
** int main(void)
** {
** 	char s1[] = "my favorite animal is";
** 	printf("%s", ft_strjoin(NULL, s1));
** }
*/
