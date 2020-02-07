/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimon <ssimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:23:37 by ssimon            #+#    #+#             */
/*   Updated: 2020/02/07 12:25:23 by ssimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	appendline(char **rest, char **line)
{
	int		i;
	char	*temp;
	int		flag;

	flag = 0;
	i = 0;
	temp = NULL;
	while (rest[0][i] != '\n' && rest[0][i] != '\0')
		i++;
	if (rest[0][i] == '\n')
		flag = 1;
	if ((temp = ft_substr(*rest, 0, i)) == NULL)
		return (-1);
	if ((*line = ft_strjoin(temp, "\0")) == NULL)
		return (-1);
	free(temp);
	temp = NULL;
	if (flag == 1)
		if ((temp = ft_strdup(&rest[0][i + 1])) == NULL)
			return (-1);
	free(*rest);
	*rest = temp;
	if (*rest == NULL && flag == 0)
		return (0);
	return (1);
}

static int	returnvalues(char **rest, char **line, int byte, int fd)
{
	if (byte < 0)
		return (-1);
	else if (byte == 0 && rest[fd] == NULL)
	{
		if ((*line = ft_strdup("")) == NULL)
			return (-1);
		return (0);
	}
	else
		return (appendline(&rest[fd], line));
}

static void	ft_free(char **rest, char *temp, int fd)
{
	free(rest[fd]);
	rest[fd] = temp;
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[FOPEN_MAX];
	int			byte;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || FOPEN_MAX <= 0)
		return (-1);
	while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = '\0';
		if (!rest[fd])
		{
			if ((rest[fd] = ft_strdup(buf)) == NULL)
				return (-1);
		}
		else
		{
			if ((temp = ft_strjoin(rest[fd], buf)) == NULL)
				return (-1);
			ft_free(rest, temp, fd);
		}
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	return (returnvalues(rest, line, byte, fd));
}
