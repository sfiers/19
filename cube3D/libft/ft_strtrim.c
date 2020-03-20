/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:53:55 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/24 16:24:50 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0' && c != set[i])
		i++;
	if (c == set[i])
		return (1);
	return (0);
}

static int		ft_beginning(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		while (ft_check(s1[i], set) && s1[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

static int		ft_ending(char const *s1, char const *set)
{
	int i;
	int len;

	len = ft_strlen(s1);
	i = len - 1;
	while (i >= 0)
	{
		while (ft_check(s1[i], set) && i >= 0)
			i--;
		return (len - i - 1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		x;
	int		len;
	int		len_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	x = ft_beginning(s1, set);
	len_s1 = ft_strlen(s1);
	i = 0;
	len = len_s1 - x - ft_ending(s1, set);
	if (len_s1 == x)
		len = x;
	if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (i < len)
	{
		new[i] = s1[x];
		i++;
		x++;
	}
	new[i] = '\0';
	return (new);
}

/*
** int main(void)
** {
** 	char s1[] = "hahaahcoucouahhaaah";
** 	char set[] = "ah";
** 	printf("%s", ft_strtrim(s1, set));
** }
*/
