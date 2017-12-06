/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:39:13 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		n_index(const char *str)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		read_rest(char **rest, char **line)
{
	int		n;

	if ((n = n_index(*rest)) == -1)
		return (0);
	*line = ft_strsub(*rest, 0, n);
	*rest += n + 1;
	return (1);
}

static int		read_buff(int fd, char **rest)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				char_count;
	int				n;
	int				r;

	r = 0;
	while ((char_count = read(fd, buff, BUFF_SIZE)))
	{
		r = 1;
		buff[char_count] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(*rest, buff);
		free(tmp);
		if ((n = n_index(*rest)) != -1)
			break ;
	}
	return (r);
}

int				get_next_line(const int fd, char **line)
{
	static char		*rest;
	int				r;

	if (!line || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (read_rest(&rest, line))
		return (1);
	if (!rest)
		rest = ft_strdup("");
	else
		rest = ft_strdup(rest);
	r = read_buff(fd, &rest);
	if (read_rest(&rest, line))
		return (1);
	*line = rest;
	return (r);
}
