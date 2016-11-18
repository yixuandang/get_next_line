/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:09:29 by ydang             #+#    #+#             */
/*   Updated: 2016/11/17 16:14:09 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;
	int		count_lines;

	fd = 0;
	printf("fd = %\n meaning we are reading from a stdinput", fd);
	if (fd != (-1))
	{
		count_lines = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			count_lines++;
			if (count_lines > 10)
				break ;
		}
	}
	return (0);
}
