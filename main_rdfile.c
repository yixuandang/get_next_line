/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rdfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:14:43 by ydang             #+#    #+#             */
/*   Updated: 2016/11/17 17:11:56 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_line_line.h"
#include "libft/includes/libft.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	int		count_lines;
	int		errors;

	if (argc != 2)
	{
		printf("\n Usage: The function can only read one file so plz give a valid input \n");
		return (1);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		printf("fd = %d\n", fd);
		if (fd != (-1))
		{
			count_lines = 0;
			errors = 0;
			line = NULL;
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				printf("The current line is: %s\n", line);
				count_lines++;
				if (count_lines > 10)//you can change it from 1 to ~ if you want.
					break ;
			}
			close (fd);
		}
		else
			printf("An error occured while opening file %s\n", argv[1]);
	}
	return (0);
}
