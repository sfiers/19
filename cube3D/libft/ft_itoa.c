/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:27:55 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 16:38:51 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int nb)
{
	unsigned int	sign;
	unsigned int	j;
	unsigned int	nbr;
	char			*str;

	str = NULL;
	sign = 0;
	if (!(str = (char*)malloc(sizeof(*str) * ft_size(nb) + 1)))
		return (NULL);
	j = ft_size(nb);
	if (nb < 0)
	{
		str[0] = '-';
		sign = 1;
		nbr = -nb;
	}
	else
		nbr = nb;
	str[j] = '\0';
	while (j-- > sign)
	{
		str[j] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/*
** int main(void)
** {
**	int nb;
**	nb = -145;
**	printf("%s", ft_itoa(nb));
** }
*/
