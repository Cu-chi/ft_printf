/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:17 by equentin          #+#    #+#             */
/*   Updated: 2025/11/14 16:31:08 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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

'-'
*/
/*
#include <stdio.h>

void	debug_print_list(t_format_list *f)
{
	printf("########################\n");
	printf("has_blk 	: %d\n", f->has_blk);
	printf("has_hex 	: %d\n", f->has_hex);
	printf("has_lad 	: %d\n", f->has_lad);
	printf("has_pad 	: %d\n", f->has_pad);
	printf("has_sgn 	: %d\n", f->has_sgn);
	printf("has_prs 	: %d\n", f->has_prs);
	printf("precision 	: %d\n", f->precision);
	printf("width 		: %d\n", f->width);
	printf("c 		: %c\n", f->c);
	printf("########################\n");
}
*/

// %c %s %p %d %i %u %x %X %%
void	ft_printf_logic(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	(void)ap;
	if (fmt_lst->c == '%')
	{
		(*printed)++;
		ft_putchar_fd(fmt_lst->c, 1);
	}
	else if (fmt_lst->c == 'c')
		write_c(fmt_lst, printed, ap);
	else if (fmt_lst->c == 's')
		write_s(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'd' || fmt_lst->c == 'i' || fmt_lst->c == 'u')
		write_diu(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'x' || fmt_lst->c == 'X')
		write_x(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'p')
		write_p(fmt_lst, printed, ap);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				printed;
	t_format_list	*fmt_lst;

	va_start(ap, fmt);
	printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt_lst = ft_get_format(fmt + 1);
			if (fmt_lst == NULL)
				return (0);
			ft_printf_logic(fmt_lst, &printed, &ap);
			fmt += fmt_lst->new_index + 2;
			free(fmt_lst);
		}
		else
		{
			write(1, fmt++, 1);
			printed++;
		}
	}
	va_end(ap);
	return (printed);
}
/*
int	main(void)
{
	void	*a;

	// printf("'%i'\n", 00101);
	// printf("'%#x'\n", -1);
	// ft_printf("'%#00d'\n", 42);
	// ft_printf("'%d'\n", 42);
	// ft_printf("'%#x'\n", 42);
	// ft_printf("'%-10d'\n", 42);
	// ft_printf("'%010d'\n", 42);
	// ft_printf("'%.0d'\n", 42);
	// ft_printf("'%#00%'\n");
	// ft_printf("'% 0-+#10.5d'\n");
	// ft_printf("%d\n", ft_printf("'%c'\n", 'a'));
	// ft_printf("%d\n", ft_printf("'%s'\n", "abc de f rrr"));
	// ft_printf("%d\n", ft_printf("'%x'\n", __UINT32_MAX__));
	a = &ft_printf;
	//ft_printf("val : %d\n", ft_printf("%p\n", a));
	ft_printf("%p", a);
	printf("%p", a);
	return (0);
}
*/
