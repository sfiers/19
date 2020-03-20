/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:16:00 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/10 18:32:19 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
**int main(void)
**{
**	printf("%d", ft_strlen("coucou"));
**}
*/
