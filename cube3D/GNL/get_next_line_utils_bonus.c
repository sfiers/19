/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:31:27 by ssimon            #+#    #+#             */
/*   Updated: 2020/02/25 13:54:40 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen(s1);
	if ((str = (char*)malloc(i + 1)) != 0)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	last;
	char			*str;

	i = 0;
	last = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str = (char*)malloc(sizeof(char) +
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	while (s2[last] != '\0')
	{
		str[last + i] = s2[last];
		++last;
	}
	str[last + i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		c1;
	const char	*str;

	i = 0;
	str = s;
	c1 = c;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			return ((char*)&str[i]);
		++i;
	}
	if (c1 == '\0')
		return ((char*)&str[i]);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !(str = malloc((len + 1))))
		return (NULL);
	if (start < (unsigned int)ft_strlen(s))
	{
		while (s[start] && len > 0)
		{
			str[i] = s[start];
			++i;
			++start;
			--len;
		}
	}
	str[i] = '\0';
	return (str);
}
