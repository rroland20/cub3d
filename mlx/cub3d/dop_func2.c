/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:14:53 by rroland           #+#    #+#             */
/*   Updated: 2021/04/05 19:17:12 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		write (1, &s[i], 1);
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

	new = (t_map *)malloc(sizeof(t_map) + 1);
	if (!(new))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_map *lst)
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
