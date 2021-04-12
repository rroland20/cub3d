/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:03:42 by rroland           #+#    #+#             */
/*   Updated: 2021/04/07 19:30:07 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	a;
	int		i;

	i = -1;
	if (!str)
		return (0);
	a = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (a + 1));
	if (!(res))
		return (0);
	while (str[++i] != 0)
		res[i] = str[i];
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	a = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (a + 1));
	if (!(res))
		return (0);
	while (s1[++j] != 0)
		res[j] = s1[j];
	while (s2[++i] != 0)
		res[j + i] = s2[i];
	res[j + i] = 0;
	return (res);
}

char	*ft_strjoin_map(char *str, int num)
{
	char	*str_new;

	while (num != 0)
	{
		str_new = ft_strjoin(str, " ");
		if (str)
			free(str);
		str = str_new;
		num--;
	}
	return (str_new);
}

int	ft_atoi(const char *str, int *i)
{
	int		result;
	char	*ss;
	int		k;
	int		j;

	result = 0;
	j = 0;
	ss = (char *)str;
	k = 1;
	while (ss[*i] == ' ')
		(*i)++;
	if (ss[*i] < '0' || ss[*i] > '9')
		return (-1);
	while (ss[*i] >= '0' && ss[*i] <= '9')
	{
		result = result * 10 + (ss[*i] - '0');
		(*i)++;
		j++;
		if (j > 5)
			return (-1);
	}
	return (result * k);
}
