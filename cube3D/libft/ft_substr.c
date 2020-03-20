/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:55:03 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/01 14:37:43 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str))
		len = 0;
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	if (!(dst = (char*)malloc(sizeof(*dst) * len + 1)))
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < len && len > 0)
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
