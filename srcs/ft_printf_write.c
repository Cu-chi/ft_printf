/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:13:02 by equentin          #+#    #+#             */
/*   Updated: 2025/11/14 16:14:50 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	write_c(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	const char	c = (char)va_arg(*ap, int);

	format_pre_conv(fmt_lst, printed);
	ft_putchar_fd(c, 1);
	(*printed)++;
	format_post_conv(fmt_lst, printed);
}

void	write_s(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	format_pre_conv(fmt_lst, printed);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*printed += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		*printed += ft_strlen(s);
	}
	format_post_conv(fmt_lst, printed);
}

void	write_x(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	const unsigned int	u = va_arg(*ap, unsigned int);

	format_pre_conv(fmt_lst, printed);
	if (fmt_lst->c == 'x')
		ft_putnbr_hex(u, "0123456789abcdef", printed);
	else
		ft_putnbr_hex(u, "0123456789ABCDEF", printed);
	format_post_conv(fmt_lst, printed);
}

void	write_p(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	void	*p;

	p = va_arg(*ap, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		*printed += 5;
	}
	else
	{
		fmt_lst->has_hex = 1;
		format_pre_conv(fmt_lst, printed);
		ft_putnbr_hex((unsigned long)p, "0123456789abcdef", printed);
	}
	format_post_conv(fmt_lst, printed);
}

void	write_diu(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	char			*a;
	unsigned int	u;
	int				di;

	if (fmt_lst->c == 'u')
	{
		u = va_arg(*ap, unsigned int);
		a = ft_itoa_u(u);
		ft_putstr_fd(a, 1);
		*printed += ft_strlen(a);
		free(a);
		return ;
	}
	di = va_arg(*ap, int);
	a = ft_itoa(di);
	ft_putstr_fd(a, 1);
	*printed += ft_strlen(a);
	free(a);
}
