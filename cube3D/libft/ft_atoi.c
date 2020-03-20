/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:26 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/22 10:58:13 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result * 10 + str[i] - '0' >= result)
			result = result * 10 + str[i++] - '0';
		else
			return (sign == 1 ? (int)LONG_MAX : (int)LONG_MIN);
	}
	return (int)(result * sign);
}

/*
** int main(void)
** {
**	char str1[] = "99999999999999999999";
**	printf("%d\n", ft_atoi(str1));
**
**	char str[] = "99999999999999999999";
**	printf("%d\n", atoi(str));
** }
*/
