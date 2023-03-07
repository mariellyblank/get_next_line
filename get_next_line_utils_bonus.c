/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblank <mblank@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:52:13 by mblank            #+#    #+#             */
/*   Updated: 2023/03/05 07:32:36 by mblank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	y;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (s1 && s1[y])
		str[i++] = s1[y++];
	y = 0;
	while (s2 && s2[y] && s2[y] != '\n')
		str[i++] = s2[y++];
	if (s2[y] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free(s1);
	return (str);
}

int	arrange(char *bf)
{
	int	i;
	int	y;
	int	isnwl;

	i = 0;
	y = 0;
	isnwl = 0;
	while (bf[i])
	{
		if (isnwl)
			bf[y++] = bf[i];
		if (bf[i] == '\n')
			isnwl = 1;
		bf[i++] = '\0';
	}
	return (isnwl);
}
