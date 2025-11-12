/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:18:27 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 13:18:04 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_split_nb_strs(char const *s, char c)
{
	size_t	nb_strs;
	char	in_str;

	nb_strs = 0;
	in_str = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (in_str == 0)
				nb_strs++;
			in_str = 1;
		}
		else
			in_str = 0;
		s++;
	}
	return (nb_strs);
}

static char	**free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (NULL);
}

static char	**ft_split_set(char const *s, char c, char **strs, size_t nb_strs)
{
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	i = 0;
	while (i < nb_strs)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		strs[i] = ft_substr(s, start, end - start);
		if (strs[i] == NULL)
			return (free_all(strs));
		start = end;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	nb_strs;

	nb_strs = ft_split_nb_strs(s, c);
	strs = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (strs == NULL)
		return (NULL);
	return (ft_split_set(s, c, strs, nb_strs));
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "!";
	char		s2;
	char		**s;
	int			i;

	s2 = ' ';
	i = 0;
	s = ft_split(s1, s2);
	while (s[i] != NULL)
	{
		printf("'%s' %p\n", s[i], s[i]);
		i++;
	}
		printf("'%s' %p\n", s[i], s[i]);
}
	*/