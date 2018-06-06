/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:20:45 by ccoupez           #+#    #+#             */
/*   Updated: 2018/04/03 17:38:38 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_to_free(char *s1, char *s2, int const tofree)
{
	if (tofree == 1)
		free(s1);
	else if (tofree == 2)
		free(s2);
	else if (tofree == 3)
	{
		free(s1);
		free(s2);
	}
	else
		return ;
}

char		*ft_strjoin_free(char *s1, char *s2, int tofree)
{
	char	*str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
		str[len_s1++] = s2[i++];
	str[len_s1] = '\0';
	ft_to_free(s1, s2, tofree);
	return (str);
}
