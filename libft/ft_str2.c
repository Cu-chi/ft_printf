/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:13:57 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 13:10:39 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i - j + 1);
		}
		else
		{
			if (j > 0)
				i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	const char	*big = "aaabcabcd";
	const char	*little = "aabc";

	printf("'%s'\n", ft_strnstr(big, little, -1));
	printf("'%s'", strnstr(big, little, -1));
	return (0);
}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	const char	*big = "test\200";
	const char	*little = "test\0";

	printf("%d\n", ft_strncmp(big, little, 6));
	printf("%d", strncmp(big, little, 6));
	return (0);
}
*/

char	*ft_strdup(const char *s)
{
	size_t	lenght;
	size_t	i;
	char	*d;

	lenght = 0;
	while (s[lenght])
		lenght++;
	d = (char *)malloc(sizeof(char) * (lenght + 1));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "helloo";
	char		*d1;
	char		*d2;

	d1 = ft_strdup(s);
	d2 = strdup(s);
	printf("%s\n", d1);
	printf("%s", d2);
	free(d1);
	free(d2);
	return (0);
}
*/