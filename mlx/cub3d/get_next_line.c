/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:30:21 by rroland           #+#    #+#             */
/*   Updated: 2021/03/10 21:03:58 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*recording(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != 0)
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			return (ft_strdup(&buff[i + 1]));
		}
		i++;
	}
	return (0);
}

int		read_in(int fd, char **rec, char **line)
{
	int		num;
	char	*tmp;
	char	*buff;

	num = 1;
	if (!(buff = (char *)malloc(101)))
		return (-1);
	while (num > 0)
	{
		num = read(fd, buff, 100);
		buff[num] = 0;
		*rec = recording(buff);
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		if (tmp)
			free(tmp);
		if (*rec)
			break ;
	}
	free(buff);
	return (num);
}

int		k(char *str, int num)
{
	if (num == 0 && str == 0)
		return (0);
	if (num != 0 && str == 0)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			num;
	char		*rec;

	if (fd < 0 || line == 0
	|| (num = read(fd, &num, 0) == -1))
		return (-1);
	*line = 0;
	rec = 0;
	if (str)
	{
		rec = recording(str);
		*line = ft_strjoin(*line, str);
		free(str);
		str = ft_strdup(rec);
		free(rec);
		if (str)
			return (1);
	}
	num = read_in(fd, &rec, line);
	str = ft_strdup(rec);
	free(rec);
	return (k(str, num));
}
