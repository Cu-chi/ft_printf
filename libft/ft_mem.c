/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:00:11 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 13:37:47 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n-- > 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = NULL;
	c = malloc(sizeof(char) * 12);
	c[0] = '\0';
	b = malloc(sizeof(char) * 12);
	b[0] = '\0';
	//printf("-> %s\n", c);
	memcpy(((void*)0), ((void*)0), 3);
	//printf("%s\n", c);
	//printf("-> %s\n", b);
	ft_memcpy(((void*)0), ((void*)0), 3);
	//printf("%s\n", b);
	free(c);
	free(b);
	return (0);
}
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*big = "he\0Boo";
	const char	*little = "he\0Alo";

	printf("%d\n", ft_memcmp(big, little, 5));
	printf("%d", memcmp(big, little, 5));
	return (0);
}
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*_s;

	i = 0;
	_s = (unsigned char *)s;
	while (i < n)
	{
		if (_s[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*str = "ab\0bbcdef";
	int			tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%p\n", ft_memchr((const void *)tab, -1, 7));
	printf("%p\n", memchr((const void *)tab, -1, 7));
	// printf("%p\n", ft_memchr((const void *)str, '\0', 10));
	// printf("%p\n", memchr((const void *)str, '\0', 10));
	// printf("%p\n", ft_memchr((const void *)str, 'e', 10));
	// printf("%p\n", memchr((const void *)str, 'e', 10));
}
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s2;

	s2 = s;
	while (n-- > 0)
		*s2++ = c;
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char	*c;
	int		i;

	c = malloc(sizeof(char) * 10);
	i = 0;
	while (i < 10)
		c[i++] = 'A';
	c[i] = '\0';
	printf("%s\n", c);
	ft_memset(c, 'B', 4);
	printf("%s\n", c);
	i = 0;
	while (i < 10)
		c[i++] = 'A';
	c[i] = '\0';
	printf("%s\n", c);
	memset(c, 'B', 4);
	printf("%s\n", c);
	return (0);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (n == 0)
		return (dest);
	if (d == s)
		return (dest);
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n-- > 0)
			*--d = *--s;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	a[] = "test move!";
	int		i;

	i = 0;
	printf("-> %s\n", a);
	ft_memmove(a + 5, a, 4);
	while (i < 12)
		printf("%c", a[i++]);
	return (0);
}
*/
