/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:42:58 by ccoupez           #+#    #+#             */
/*   Updated: 2018/02/28 15:58:48 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*check_fd(int const fd, t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *list;
	tmp2 = NULL;
	while (tmp != NULL)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, (size_t)fd);
	if (tmp2 != NULL)
		tmp2->next = tmp;
	else
		*list = tmp;
	return (tmp);
}

static int		get_line(t_list *list, char **line)
{
	char	*str;
	size_t	i;

	i = 0;
	if (list->content)
	{
		while (((char *)list->content)[i] && ((char *)list->content)[i] != '\n')
			i++;
		str = ft_strsub(((char *)list->content), 0, i);
		*line = ft_strjoin_free(*line, str, 3);
		if (((char *)list->content)[i] == '\n')
		{
			str = ft_strdup(((char *)list->content) + i + 1);
			ft_strdel((char**)&(list->content));
			list->content = str;
			return (1);
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	
	tmp = check_fd(fd, &list);
	*line = ft_strnew(0);
	if (get_line(tmp, line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !ft_strchr(buf, '\n'))
	{
		
		buf[ret] = '\0';
		*line = ft_strjoin_free(*line, buf, 1);
	}
	buf[ret] = '\0';
	tmp->content = ft_strdup(buf);
	if (get_line(tmp, line) == 0 && ret == 0 && ft_strlen(*line) == 0)
		return (0);;
	return (1);
}
