/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:12:39 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 16:46:33 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned int	i;
	unsigned char	*dest2;

	dest2 = (unsigned char*)dest;
	i = 0;
	while (i < len)
	{
		dest2[i] = value;
		i++;
	}
	return (dest2);
}
/*
**int main(void)
**{
**	char str[50] = "GeeksForGeeks is for programming geeks.";
**	printf("\nBefore memset(): %s\n", str);
**	// Fill 8 characters starting from str[13] with '.'
**	memset(str + 13, '.', 8*sizeof(char));
**	printf("After memset():  %s", str);
**	return 0;
**}
*/
