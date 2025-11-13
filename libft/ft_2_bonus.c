/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:16:17 by equentin          #+#    #+#             */
/*   Updated: 2025/11/12 11:31:19 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		del(lst->content);
	else
		free(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
/*
static void	test(void *a)
{
	printf("contenu %s\n", (char *)a);
	//free(a);
}

int	main(void)
{
	t_list	*nl;
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	nl = ft_lstnew("test");
	ft_lstadd_front(&nl, ft_lstnew("new"));
	ft_lstadd_front(&nl, ft_lstnew("new2"));
	ft_lstadd_front(&nl, ft_lstnew("new3"));
	ft_lstclear(&nl, &test);
	return (0);
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
static void	test(void *a)
{
	printf("contenu %s\n", (char *)a);
}

int	main(void)
{
	t_list	*nl;
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	nl = ft_lstnew("test");
	ft_lstadd_front(&nl, ft_lstnew("new"));
	ft_lstadd_front(&nl, ft_lstnew("new2"));
	ft_lstadd_front(&nl, ft_lstnew("new3"));
	ft_lstiter(nl, &test);
	return (0);
}
*/

void	*ft_lstmap_clear(t_list **new_lst, void *created_content,
		void (*del)(void *))
{
	if (created_content)
		del(created_content);
	ft_lstclear(new_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*created_node;
	void	*created_content;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		created_content = f(lst->content);
		if (created_content == NULL)
			return (ft_lstmap_clear(&new_lst, NULL, del));
		created_node = ft_lstnew(created_content);
		if (created_node == NULL)
			return (ft_lstmap_clear(&new_lst, created_content, del));
		ft_lstadd_back(&new_lst, created_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
#include <stdio.h>

static void	*testf(void *a)
{
	char	*new;

	new = malloc(sizeof(char) * 3);
	if (new == NULL)
		return (NULL);
	new = "42";
	return (new);
}

static void	testprint(void *a)
{
	printf("contenu %s\n", (char *)a);
}

static void	testdel(void *a)
{
	free(a);
}

int	main(void)
{
	t_list	*nl;
	t_list	*new;
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	nl = ft_lstnew("test");
	ft_lstadd_front(&nl, ft_lstnew("new"));
	ft_lstadd_front(&nl, ft_lstnew("new2"));
	ft_lstadd_front(&nl, ft_lstnew("new3"));
	new = ft_lstmap(nl, &testf, &testdel);
	ft_lstiter(new, &testprint);
	if (new != NULL)
		ft_lstclear(&new, &testdel);
	ft_lstclear(&nl, &testdel);
	return (0);
}
*/
