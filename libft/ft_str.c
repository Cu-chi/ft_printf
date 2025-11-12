/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:37:14 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 10:23:29 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	tsrc;

	tsrc = 0;
	while (src[tsrc])
		tsrc++;
	if (size == 0)
		return (tsrc);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (tsrc);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght_dest;
	size_t	lenght_src;

	lenght_src = 0;
	while (src[lenght_src])
		lenght_src++;
	if (size == 0)
		return (lenght_src);
	lenght_dest = 0;
	while (dst[lenght_dest] && lenght_dest < size)
		lenght_dest++;
	i = 0;
	while (src[i] && lenght_dest + i < size - 1)
	{
		dst[lenght_dest + i] = src[i];
		i++;
	}
	if (size > lenght_dest)
	{
		dst[lenght_dest + i] = '\0';
		return (lenght_dest + lenght_src);
	}
	return (lenght_src + size);
}
/* TODO
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	const char	s[] = " test";
	char	d[] = "hello";
	char	d2[] = "hello";
	char	d3[] = "hello";
	char	d4[] = "hello";
	char	d5[] = "hello";
	char	d6[] = "hello";

	// printf("%zu\n", ft_strlcat(d, s, 10));
	// printf("%zu\n", strlcat(d2, s, 10));

	printf("%zu\n", ft_strlcat(d3, s, 4));
	printf("%zu\n", strlcat(d4, s, 4));
	printf("%zu\n", ft_strlcat(d5, s, 0));
	printf("%zu\n", strlcat(d6, s, 0));
}
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "abbbcdef";

	printf("%s\n", ft_strchr(str, 'b'));
	printf("%s\n", strchr(str, 'b'));
	printf("%s\n", ft_strchr(str, '\0'));
	printf("%s\n", strchr(str, '\0'));
	printf("%s\n", ft_strchr(str, 'z'));
	printf("%s\n", strchr(str, 'z'));
	printf("-----strrchr\n");
	printf("%s\n", ft_strrchr(str, 'b'));
	printf("%s\n", strrchr(str, 'b'));
	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", strrchr(str, '\0'));
	printf("%s\n", ft_strrchr(str, 'z'));
	printf("%s\n", strrchr(str, 'z'));
}
*/
