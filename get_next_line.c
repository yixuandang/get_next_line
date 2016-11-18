/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:03:27 by ydang             #+#    #+#             */
/*   Updated: 2016/11/06 23:03:28 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <unistd.h>

t_gnl	*ini_gnl(t_list **lst, int fd)
{
	t_gnl	*gnl;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		gnl = (t_gnl *)(temp->content);
		if (gnl->fd == fd)
			return (gnl);
		temp = temp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buf = ft_strnew(BUFF_SIZE);
	gnl->count = BUFF_SIZE;
	gnl->i = BUFF_SIZE;
	gnl->fd = fd;
	gnl->nl = 1;
	temp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_memdel((void **)&gnl);
	ft_lstadd(lst, temp);
	return ((t_gnl *)(temp->content));
}

char	*get_reminder(t_gnl *gnl)
{
	int i;

	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl));
}

void	free_gnl(t_list **lst, int fd, char **str)
{
	t_gnl	*gnl;
	t_list	**temp;
	t_list	*ptr;

	temp = lst;
	while (*temp)
	{
		gnl = (t_gnl *)((*temp)->content);
		if (gnl->fd == fd)
			break ;
		*temp = ((*temp)->next);
	}
	if (*temp)
	{
		ptr = (*temp)->next;
		ft_strdel(&(gnl->buf));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)temp);
		*temp = ptr;
	}
	ft_strdel(str);
}

int		check_buffer(t_gnl *gnl, t_list **lst, char **temp, char **line)
{
	if (gnl->i == gnl->count)
	{
		gnl->count = read(gnl->fd, gnl->buf, BUFF_SIZE);
		if (gnl->count == -1)
		{
			free_gnl(lst, gnl->fd, temp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->count == 0)
		{
			if (gnl->nl == 0)
			{
				*line = *temp;
				return (1);
			}
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl = ini_gnl(&lst, fd);
	tmp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if ((ret = check_buffer(gnl, &lst, &tmp, line)) != 0)
			return (ret);
		while (gnl->i < gnl->count)
		{
			tmp = ft_strmerge(tmp, get_reminder(gnl));
			if (gnl->nl)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	free_gnl(&lst, fd, &tmp);
	return (0);
}
