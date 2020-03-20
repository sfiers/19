/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:02:01 by lduhamel          #+#    #+#             */
/*   Updated: 2019/10/21 16:52:36 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *src, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * n + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int		ft_nb_strings(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c)
		j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			j++;
		i++;
	}
	return (j);
}

static void		ft_free(char **ptr)
{
	int j;

	j = 0;
	while (ptr[j] != NULL)
	{
		free(ptr[j]);
		j++;
	}
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**ptr;

	i = 0;
	j = 0;
	if (s == NULL || (!(ptr = malloc(sizeof(*ptr) * ft_nb_strings((char *)s, c)
			+ 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_nb_strings((char*)s, c))
	{
		index = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			index++;
			i++;
		}
		if ((ptr[j++] = ft_strndup(s + i - index, index)) == NULL)
			ft_free(ptr);
	}
	ptr[j] = 0;
	return (ptr);
}

/*
** int main(void)
** {
**     char *s = " olol                ";
**     int i = 0;
**     char **res = ft_split(s, ' ');
**     while (res[i]) {
**         printf("%s\n", res[i]);
**         i++;
**     }
** }
*/
