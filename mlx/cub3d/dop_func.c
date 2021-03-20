/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:03:42 by rroland           #+#    #+#             */
/*   Updated: 2021/03/19 19:07:42 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlen(const char *c)
{
	int i;

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
	if (!(res = (char *)malloc(sizeof(char) * (a + 1))))
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
	if (!(res = (char *)malloc(sizeof(char) * (a + 1))))
		return (0);
	while (s1[++j] != 0)
		res[j] = s1[j];
	while (s2[++i] != 0)
		res[j + i] = s2[i];
	res[j + i] = 0;
	return (res);
}

int			ft_atoi(const char *str, int *i)
{
	int		result;
	char	*ss;
	int		k;

	result = 0;
	ss = (char *)str;
	k = 1;
	while(ss[*i] == ' ')
		(*i)++;
	if (ss[*i] < '0' || ss[*i] > '9')
		return (-1);
	while (ss[*i] >= '0' && ss[*i] <= '9')
	{
		result = result * 10 + (ss[*i] - '0');
		(*i)++;
	}
	return (result * k);
}

t_map	*ft_lstlast(t_map *lst)
{
	t_map	*a;

	a = lst;
	if (a == NULL)
		return (0);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*lst1;

	lst1 = *lst;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		lst1 = ft_lstlast(*lst);
		lst1->next = new;
	}
}

t_map	*ft_lstnew(char *content)
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map) + 1)))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int		ft_lstsize(t_map *lst)
{
	int		a;
	t_map	*b;

	b = lst;
	a = 0;
	if (b == NULL)
		return (0);
	while (b)
	{
		a++;
		b = b->next;
	}
	return (a);
}