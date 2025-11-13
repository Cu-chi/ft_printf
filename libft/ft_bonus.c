/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:16:17 by equentin          #+#    #+#             */
/*   Updated: 2025/11/12 17:05:45 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*nl;

	nl = (t_list *)malloc(sizeof(t_list));
	if (nl == NULL)
		return (NULL);
	nl->content = content;
	nl->next = NULL;
	return (nl);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*nl;

	nl = ft_lstnew("test");
	printf("%s", (char *)nl->content);
	return (0);
}
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*nl;

	nl = ft_lstnew("test");
	ft_lstadd_front(&nl, ft_lstnew("new"));
	printf("TAILLE %d\n", ft_lstsize(nl));
	return (0);
}
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		ft_lstadd_front(lst, new);
}
