/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 12:43:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 20:09:04 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		get_fd(char *name)
{
	return (open(name, O_RDONLY));
}

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = get_fd("test");
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);	
	}
	printf("Ret : %d\n\n", ret);
	close(fd);
	return (0);
}
