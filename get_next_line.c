/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 15:56:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		n_index(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		read_rest(char **line, char **rest)
{
	int		n;

	if (!*rest)
		return (0);
	if ((n = n_index(*rest)) < 0)
	{
		*line = ft_strjoin(*line, *rest);
		*rest = NULL;
		return (0);
	}
	*line = ft_strjoin(*line, ft_strsub(*rest, 0, n));
	*rest = ft_strsub(*rest, n + 1, ft_strlen(*rest) - n + 1);
	return (1);
}

int		read_buff(int fd, char **line, char **rest)
{
	int		char_count;
	int		n;
	char	buff[BUFF_SIZE + 1];

	while ((char_count = read(fd, buff, BUFF_SIZE)))
	{
		if ((n = n_index(buff)) >= 0)
		{	
			*line = ft_strjoin(*line, ft_strsub(buff, 0, n));
			*rest = ft_strsub(buff, n + 1, BUFF_SIZE - n + 1);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (char_count > 0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = ft_strdup("");
	if (read_rest(line, &rest))
		return (1);
	return (read_buff(fd, line, &rest));
}
