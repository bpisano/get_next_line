/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:10:53 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 20:08:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		index_of(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		is_rest(char **line, char **rest)
{
	int		n_index;

	if (!ft_strchr(*rest, '\n'))
		return (0);
	n_index = index_of(*rest, '\n');
	*line = ft_strjoin(*line, ft_strsub(*rest, 0, n_index));
	*rest = ft_strsub(*rest, n_index + 1, ft_strlen(*rest) - n_index + 1);
	return (1);
}

static int		read_fd(int fd, char **line, char **rest)
{
	int		char_count;
	int		n_index;
	char	buff[BUFF_SIZE + 1];

	while ((char_count = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_strchr(buff, '\n'))
		{
			n_index = index_of(buff, '\n');
			*line = ft_strjoin(*line, ft_strsub(buff, 0, n_index));
			*rest = ft_strsub(buff, n_index + 1, BUFF_SIZE - n_index + 1);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (char_count > 0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*rest;

	if (!line || fd < 0)
		return (-1);
	*line = ft_strdup("a");
	if (is_rest(line, &rest))
		return (0);
	if (rest)
	{
		*line = ft_strjoin(*line, rest);
		rest = NULL;
	}
	return (read_fd(fd, line, &rest));
}
