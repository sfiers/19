/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:00:17 by lduhamel          #+#    #+#             */
/*   Updated: 2020/03/19 17:25:57 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./GNL/get_next_line.h"
#include <stdio.h>
#include "wolf.h"

int		ft_strlen2(char *s) 
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			n++;
		i++;
	}
	return(i - n);
}

int		ft_strlen1(char *s) // a supp : doublon
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return(i);
}

int		cleanline(t_maptab *tab, t_info *info, char **line, char **newline)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(*newline = (char*)malloc(sizeof(char) * (ft_strlen2(*line) + 1))))
		return(0);
	while ((*line)[i] != '\0')
	{
		while ((*line)[i] == ' ')
			i++;
		if (tab->counter == 0)
		{
			if ((*line)[i] != '1')
				tab->error.ret = -1;
		}
		else
			tab->error.ret = check_vside(tab, info, &tab->line, i);
		// // // printf("letter = %d\n", tab->letter);
		if (tab->error.ret < 0)
			return (-1);
		(*newline)[j] = (*line)[i];
		i++;
		j++;
	}
	(*newline)[j] = '\0';
	return (1);
}

// void	init_maptab(t_maptab *tab)
// {
// 	tab->letter = 0;
// 	tab->ret2 = 0;
// }

int		error_ret(t_error *error)
{
	error->msg = NULL;
	if (error->ret < 0)
	{
		if (error->ret == -1)
			error->msg = ft_strdup1("Map must be closed by walls (1)");
		if (error->ret == -2)
			error->msg = ft_strdup1("Map must only have one position letter");
		if (error->ret == -3)
			error->msg = ft_strdup1("Map must only have 0, 1, 2, N, W, S or E");
		if (error->ret == -4)
			error->msg = ft_strdup1("Map should not have empty line");
		return (1);
	}
	return (0);
}

int	check_vside(t_maptab *tab, t_info *info, char **line, int i)
{
	if ((*line)[0] != '1' || (*line)[ft_strlen1(*line) - 1] != '1')
		return (-1);
	if ((*line)[i] == 'N' || (*line)[i] == 'E' || (*line)[i] == 'S' || (*line)[i] == 'W' || (*line)[i] == '0' || (*line)[i] == '1' || (*line)[i] == '2')
	{
		if ((*line)[i] == '2')
			info->nbsprite++;
		if ((*line)[i] != '0' && (*line)[i] != '1' && (*line)[i] != '2' && tab->letter == 1)
			return (-2);
		if ((*line)[i] != '0' && (*line)[i] != '1' && (*line)[i] != '2' && tab->letter == 0)
		{
			(*line)[i] =  ((*line)[i] == 'N' ? '3' : (*line)[i]);
			(*line)[i] =  ((*line)[i] == 'W' ? '4' : (*line)[i]);
			(*line)[i] =  ((*line)[i] == 'S' ? '5' : (*line)[i]);
			(*line)[i] =  ((*line)[i] == 'E' ? '6' : (*line)[i]);
			tab->letter = 1;
		}
	}
	else
		return (-3);
	return(1);
}

char	*ft_strdup1(char *s1) // a supp : doublon
{
	char	*ptr;
	int		i;

	if (!s1 || !(ptr = (char*)malloc(sizeof(char) * (ft_strlen1(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_join_lines(char *temp, char *line, int counter)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (line == NULL || (line == NULL && line == NULL))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * ((ft_strlen1 (temp)) + (ft_strlen1(line) + 2)))))
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

void	ft_putstr1(char *s) // doublon
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		put_error(t_error *error)
{
	error_ret(error);
	if (error->ret < 0)
		ft_putstr1("Error\n");
	ft_putstr1(error->msg);
	//free(tab->error);
}

int			first_string(t_maptab *tab, t_info *info)
{
	char *newline;
	int i;
	int j;
	info->nbsprite = 0;
	tab->ret = 1;
	while(tab->ret == 1)
	{
		//init_maptab(tab);
		tab->ret = get_next_line(tab->fd, &tab->line);
		//printf("line = %s\n", tab->line);
		if (tab->line[0] == '\0')
			tab->error.ret = -4;
		cleanline(tab, info, &tab->line, &newline);
		if (tab->error.ret < 0)
		{
			if (tab->map_str1 != NULL)
				free(tab->map_str1);
			return(-1);
		}
		tab->map_str1 = ft_join_lines(tab->map_str1, newline, tab->counter);
		free(tab->line);
		tab->counter++;
	}


	// verifier derniere ligne
	// letter

	//len_map(tab);
	// for(j=0; j < 24; j++)
  	// {
    // for(i = 0; i < 2; i++)
    // {
    //   // // printf("%d",tab->len_tab[j][i]);
    // }
    // // // printf("\n");
	//}
	// 		if (check_hside(tab->line, tab->len) == -1)
	// 			return (-1);
	// 	}
	// 	if ((tab->check_len = ft_strlen(tab->line)) != tab->len)
	// 		return (-1);
	// 	if (check_vside(&tab->line, tab->len, &tab->letter) == -1)
	// 		return (-1);
	// 	tab->map_str = ft_join_lines(tab->map_str, tab->line, tab->len, tab->counter);
	// 	free(tab->line);
	// 	tab->counter++;
	// }
	// if (check_hside(tab->line, tab->len) == -1)
	// 	return (-1);
	// if (tab->letter != 1)
	// 	return (-1);
	// tab->lines_nb = ft_lines_number(tab->map_str);
	return (1);
}

int		len_row(t_maptab *tab)
{
	int i;
	int len1;
	int len2;
	int len_max;

	i = 0;
	len1 = 0;
	len2 = 0;
	while(tab->map_str1[i] != '\0')
	{
		while (tab->map_str1[i] != '\n')
		{
			i++;
			len1++;
		}
		len_max = (len1 > len2 ? len1 : len2);
		len2 = len_max;
		len1 = 0;
		i += 1;
	}
	return(len_max);
}

int			second_string(t_maptab *tab)
{
	int i;
	int j;
	int limit;

	i = 0;
	j = 0;
	tab->len_max = len_row(tab);
	limit = tab->len_max;
	if (!(tab->map_str2 = (char*)malloc(sizeof(char) * (((tab->len_max + 1) * tab->counter) + 1))))
		return (-1);
	tab->counter = 0;
	while (tab->map_str1[i] != '\0')
	{
		while (tab->map_str1[i] != '\0' && tab->map_str1[i] != '\n')
			tab->map_str2[j++] = tab->map_str1[i++];
		while (j < limit)
		{
			tab->map_str2[j] = '9';
			j++;
		}
		tab->map_str2[j++] = tab->map_str1[i++];
		tab->counter++;
		limit = (limit + tab->len_max + 1);
	}	
	tab->map_str2[j] = '\0';
	return(1);
}

int		str_to_tab(t_maptab *tab)
{
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	tab-> i = 0;
	if (!(tab->tab = malloc(sizeof(int*) * (tab->counter))))
		return (-1);
	while (tab->i < tab->counter)
	{
		if (!(tab->tab[tab->i++] = malloc(sizeof(int) * tab->len_max)))
		{
			free(tab->tab);
			return (-1);
		}
	}
	while (j < tab->counter)
	{
		while (tab->map_str2[k] != '\n')
		{
			(tab->tab)[j][i] = tab->map_str2[k] - '0';
		//	// // printf("tab->tab[j][i] = %d\n", tab->tab[j][i]);
			k++;
			i++;
		}
		i = 0;
		k++;
		j++;
	}
	return (1);
}

int 	verify_wall(t_maptab *tab, int x, int y)
{
	if (tab->tab[y][x + 1] == 1)
	{
		if (tab->tab[y+1][x+1] != 1 || tab->tab[y-1][x+1] != 1)
		{
		//	error->ret = -1;
			return (-1);
		}
		// if (tab->tab[y-1][x+1] != 1)
		// {
		// 	// // printf("coucou\n");
		// 	while (x < (tab->len_max - 1) && tab->tab[y][x] == 1)
		// 	{
		// 		// // printf("x = %d\n", x);
		// 		if (tab->tab[y+1][x] == 1)
		// 			return (1);
		// 		x++;
		// 	}
		// 	error->ret = -1;
		// 	return (-1);
		// }
	}
	else
	{
		//error->ret = -1;
		return (-1);
	}
	return (1);
}

int		lastcheck_closing(t_maptab *tab, t_error *error)
{
	int x;
	int y;

	y = 1;
	x = (tab->len_max - 1);
	// printf("error = %d\n", error->ret);
	while (y < (tab->counter - 1) && x >= 0)
	{
		while (tab->tab[y][x] == 9 || tab->tab[y][x] == 1)
			x--;
		// printf("y = %d\n", y);
		// printf("x = %d\n", x);
		if (tab->tab[y-1][x+1] != 1)
		{
			x++;
		//	printf("x = %d\n", x);
			if (verify_wall(tab, x, y) == -1)
			{
				error->ret = -1;			
				return (-1);
			}
		}																																																												
		if (tab->tab[y+1][x+1] != 1)
		{
			x++;
			if (verify_wall(tab, x, y) == -1)
			{
				while (x < (tab->len_max) && tab->tab[y][x] == 1)
				{
			//		// // printf("x = %d\n", x);
					if (tab->tab[y+1][x] == 1)
						return (1);
					x++;
				}
				error->ret = -1;
				return (-1);
			}
		}
		y++;
		x = (tab->len_max - 1);
	}
	return (1);
}

int	parsing(t_maptab *tab, t_info *info)
{
	int i;
	int j;
	int ret;
	tab->counter = 0;
	tab->letter = 0;
	tab->map_str1 = NULL;
	tab->i = 0;
	tab->error.ret = 0;
	if ((tab->fd = open("map.txt", O_RDONLY)) < 0)
		return (-1);
	if (first_string(tab, info) == -1 || second_string(tab) == -1 || str_to_tab(tab) == -1 || lastcheck_closing(tab, &tab->error) == -1)
	{
		put_error(&tab->error);
		return(-1);
	}
	//printf("nbsprite = %d\n", info->nbsprite);
	// printf("map_str1 = %s\n", tab->map_str1);
	// second_string(tab, error);
	// // // printf("%s\n", tab->map_str2);
	// // if (!(tab->tab = malloc(sizeof(int*) * (tab->counter))))
	// // 	return (-1);
	// // while (tab->i < tab->counter)
	// // {
	// // 	if (!(tab->tab[tab->i++] = malloc(sizeof(int) * tab->len_max)))
	// // 	{
	// // 		free(tab->tab);
	// // 		return (-1);
	// // 	}
	// // }
	// str_to_tab(tab);
	// if (lastcheck_closing(tab, error) == -1)
	// {
	// 	put_error(error);
	// 	return (-1);
	// }
	// for(j=0; j < tab->counter; j++)
  	// {
    // for(i = 0; i < tab->len_max; i++)
    // {
    //   // // printf("%d",tab->tab[j][i]);
    // }
    // // // printf("\n");
	// }
	close(tab->fd);
	return(0);
}

// int main()
// {
// 	t_maptab	tab;
// 	t_error 	error;
// 	t_info		info;
// 	if (parsing(&tab, &info) == -1)
// 		return (-1);
// 	// while(1)
// 	// {
// 	// 	tab.len_tab = 0;
// 	// }
// }