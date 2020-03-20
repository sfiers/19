/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:48:15 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 16:46:43 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}
