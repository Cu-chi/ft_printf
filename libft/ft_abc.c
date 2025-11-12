/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:48:04 by equentin          #+#    #+#             */
/*   Updated: 2025/11/11 07:55:28 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	n;
	int					m;

	i = 0;
	n = 0;
	m = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			m = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - '0';
		i++;
		if (n > LONG_MAX && m == -1)
			return (0);
		else if (n >= LONG_MAX && m == 1)
			return (-1);
	}
	return (n * m);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// printf("%d\n", atoi("    - 011"));
	// printf("%d\n", ft_atoi(" - 011"));
	// printf("%d\n", atoi("    -011"));
	// printf("%d\n", ft_atoi(" -011"));
	// printf("%d\n", atoi("       -01 1"));
	// printf("%d\n", ft_atoi("    -01 1"));
	// printf("%d\n", atoi("    +011"));
	// printf("%d\n", ft_atoi(" +011"));
	// printf("%d\n", atoi("				 -018981"));
	// printf("%d\n", ft_atoi("			-018981"));
	// printf("%d\n", atoi("   +01 1"));
	// printf("%d\n", ft_atoi("+01 1"));
	printf("%d\n", atoi("   -9223392036854976810"));
	printf("%d\n", ft_atoi("-9223392036854976810"));
	// printf("%d\n", atoi("         -9223372036854775876"));
	// printf("%d\n", ft_atoi("      -9223372036854775876"));
}
*/

void	ft_bzero(void *s, size_t n)
{
	char	*s2;

	s2 = s;
	while (n-- > 0)
		*s2++ = 0;
}
/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	*s;

	s = "test";
	printf("%s\n", s);
	bzero(s, 40);
	printf("%s\n", s);
	return (0);
}
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	fsize;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb <= __SIZE_MAX__ / size)
	{
		fsize = nmemb * size;
		array = malloc(fsize);
		if (array == NULL)
			return (NULL);
		ft_bzero(array, fsize);
		return (array);
	}
	return (NULL);
}
