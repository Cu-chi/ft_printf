/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:17 by equentin          #+#    #+#             */
/*   Updated: 2025/11/12 13:45:44 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

// %c %s %p %d %i %u %x %X %%

/*
flag
' ' -> espace avant si >= 0
	-> pas d'espace si < 0

'+' -> ajoute + si >= 0
	-> laisse - si < 0
!!! si '+' alors ' ' pas pris en compte

'#'	-> ajoute 0x devant format x
	-> ajoute 0X devant format X
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	c;
	char	*s;
	size_t	i;
	char	need_fmt;

	va_start(ap, fmt);
	need_fmt = 0;
	i = 0;
	while (fmt[i])
	{
		if (!need_fmt && fmt[i] == '%')
			need_fmt = 1;
		else if (need_fmt && fmt[i] == 'c')
		{
			c = (char)va_arg(ap, int);
			write(1, &c, 1);
		}
		else if (need_fmt && fmt[i] == 's')
		{
			s = va_arg(ap, char *);
			write(1, s, ft_strlen(s));
		}
		else
		{
			need_fmt = 0;
			write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("%c %s", '>', av[1]);
	printf("'%+d'\n", 42);
	printf("'% d'\n", 42);
	printf("'%#x'\n", 42);
	printf("'%-10d'\n", 42);
	printf("'%010d'\n", 42);
	printf("'%.2147483649d'\n", 42);
	printf("'%%'\n");
	return (0);
}
