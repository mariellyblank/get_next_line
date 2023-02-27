/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblank <mblank@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:26:59 by mblank            #+#    #+#             */
/*   Updated: 2022/12/22 16:29:36 by mblank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!bf[0])
		read(fd, bf, BUFFER_SIZE);
	bf[0] = 0;
	while (bf[0])
	{
		str = ft_strjoin(str, bf);
		if (!str)
			return (NULL);
		if (arrange(bf) == 1)
			break ;
		if (read(fd, bf, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		bf[read(fd, bf, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/* int main()
{
	char *line;
	int		fd1;
	fd1 = open("tst.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
		line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
} */
