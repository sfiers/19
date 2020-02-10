/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimon <ssimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:00:17 by lduhamel          #+#    #+#             */
/*   Updated: 2020/02/10 00:45:16 by ssimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

// int		ft_strlen(char *s)
// {
// 	int i;

// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return(i);
// }

void		filling_tab(int lines_nb, int len, int ***tab, char *map_str)
{
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	while (j < lines_nb)
	{
		while (i < len)
		{
			(*tab)[j][i] = map_str[k] - '0';
			//// printf("(*tab)[j][i] = %d\n", (*tab)[j][i]);
			k++;
			i++;
		}
		i = 0;
		k++;
		j++;
	}
}

int			ft_lines_number(char *map_str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

char		*ft_join_lines(char *temp, char *line, int len, int counter)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line == NULL || (line == NULL && line == NULL))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (((len + 1) * counter)) + (len + 1) + 1)))
		return (NULL);
	while (temp && temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	while (line && line[j])
		str[i++] = line[j++];
	str[i] = '\n';
	str[i+1] = '\0';
	if (temp != NULL)
		free(temp);
	return (str);
}

int	check_hside(char *s, int len)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (i < len && s[i] == '1')
		i++;
	if (i == len)
		return (1);
	return(-1);
}

int	check_vside(char **line, int len, int *letter)
{
	int i;

	i = 0;
	// if (*line == NULL)
	// 	return (0);
	while (i < len)
	{
		if ((*line)[0] != '1' || (*line)[len -1] != '1')
			return (-1);
		if ((*line)[i] == 'N' || (*line)[i] == 'E' || (*line)[i] == 'S' || (*line)[i] == 'W' || (*line)[i] == '0' || (*line)[i] == '1' || (*line)[i] == '2')
		{
			if ((*line)[i] != '0' && (*line)[i] != '1' && (*line)[i] != '2' && *letter == 1)
				return (-1);
			if ((*line)[i] != '0' && (*line)[i] != '1' && (*line)[i] != '2' && *letter == 0)
			{
				(*line)[i] =  ((*line)[i] == 'N' ? '3' : (*line)[i]);
				(*line)[i] =  ((*line)[i] == 'W' ? '4' : (*line)[i]);
				(*line)[i] =  ((*line)[i] == 'S' ? '5' : (*line)[i]);
				(*line)[i] =  ((*line)[i] == 'E' ? '6' : (*line)[i]);
				*letter = 1;
			}
		}
		else
			return (-1);
		i++;
	}
	return(1);
}

int			start(t_maptab *tab)
{
	tab->ret = 1;
	while(tab->ret == 1)
	{
		tab->ret = get_next_line(tab->fd, &tab->line);
		if (tab->counter == 0)
		{
			tab->len = ft_strlen(tab->line);
			// if (check_hside(tab->line, tab->len) == -1)
			// 	return (-1);
		}
		if ((tab->check_len = ft_strlen(tab->line)) != tab->len)
			return (-1);
		// if (check_vside(&tab->line, tab->len, &tab->letter) == -1)
		// 	return (-1);
		tab->map_str = ft_join_lines(tab->map_str, tab->line, tab->len, tab->counter);
		free(tab->line);
		tab->counter++;
	}
	// if (check_hside(tab->line, tab->len) == -1)
	// 	return (-1);
	// if (tab->letter != 1)
	// 	return (-1);
	tab->lines_nb = ft_lines_number(tab->map_str);
	return (1);
}

int	parsing(t_maptab *tab)
{
	int i;
	int j;

	tab->counter = 0;
	tab->letter = 0;
	tab->map_str = NULL;
	tab->i = 0;
	if ((tab->fd = open("map.txt", O_RDONLY)) < 0)
		return (-1);
	if (start(tab) == -1)
		return (-1);
	if (!(tab->tab = malloc(sizeof(int*) * (tab->lines_nb + 1))))
		return (-1);
	while (tab->i < tab->lines_nb)
	{
		if (!(tab->tab[tab->i++] = malloc(sizeof(int) * tab->len)))
		{
			free(tab->tab);
			return (-1);
		}
	}
	filling_tab(tab->lines_nb, tab->len, &tab->tab, tab->map_str);
	// for(j=0; j < tab->lines_nb; j++)
  	// {
    // for(i = 0; i < tab->len; i++)
    // {
    //   // printf("%d",tab->tab[j][i]);
    // }
    // // printf("\n");
	// }
	close(tab->fd);
	return(0);
}