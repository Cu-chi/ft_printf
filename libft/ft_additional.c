/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:08:21 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 14:32:35 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	size_t			count;
	size_t			i;
	char			*sub;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	count = 0;
	while (s[start + count] && count < len)
		count++;
	sub = (char *)malloc(sizeof(char) * (count + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && count--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "hola";
	char		*sub;

	sub = ft_substr(s, 0, 0);
	printf("RESULT : '%s' (ptr = %p)", sub, &sub);
	free(sub);
}
	*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;
	char	*join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = (s1_len + s2_len + 1);
	join = (char *)malloc(sizeof(char) * size);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "hello";
	const char	*s2 = "world";
	char		*join;

	join = ft_strjoin(s1, s2);
	printf("RESULT : %s\n", join);
	free(join);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (start < end && ft_strchr(set, s1[end]) != NULL)
		end--;
	if (end != ft_strlen(s1))
		end++;
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "";
	const char	*s2 = "";
	char		*trim;

	trim = ft_strtrim(s1, s2);
	printf("RESULT : '%s'\n", trim);
	free(trim);
}
*/

static int	ft_itoa_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*a;
	int				size;
	unsigned int	nb;

	size = ft_itoa_size(n);
	a = (char *)ft_calloc(size + 1, sizeof(char));
	if (a == NULL)
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	while ((n < 0 && size > 1) || (n >= 0 && size > 0))
	{
		size--;
		a[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*trim;

	trim = ft_itoa(-2147483648);
	printf("RESULT : '%s'\n", trim);
	free(trim);
}
*/
