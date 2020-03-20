/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:09:22 by lduhamel          #+#    #+#             */
/*   Updated: 2020/02/22 09:51:19 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
