/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblank <mblank@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:52:10 by mblank            #+#    #+#             */
/*   Updated: 2023/03/02 16:28:04 by mblank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	bf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (bf[fd][0] || read(fd, bf[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, bf[fd]);
		if (ft_strlen(bf[fd]) == 0)
			return (str);
		if (arrange(bf[fd]) == 1)
			break ;
		if (read(fd, bf[fd], 0) < 0)
		{
			free(str);
			return (NULL);
		}
	}
	return (str);
}
