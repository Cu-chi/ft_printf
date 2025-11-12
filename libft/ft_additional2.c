/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:08:21 by equentin          #+#    #+#             */
/*   Updated: 2025/11/12 11:09:22 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!f)
		return (NULL);
	i = 0;
	new = ft_strdup(s);
	if (new == NULL)
		return (NULL);
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
