/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 12:16:30 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 13:17:40 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		get_fd(char *file)
{
	return (open(file, O_RDONLY));
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	int		l;
	char 	*line;

	if (ac == 2)
	{
		fd = get_fd(av[1]);
		while ((l = get_next_line(fd, &line)) == 1)
		{
			printf("%s\n", line);
		}
		printf("Final : %s\n", line);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		fd = get_fd(av[i]);
		while ((l = get_next_line(fd, &line)) == 1)
		{
			printf("%s", line);
		}
		i++;
	}
	return (0);
}
