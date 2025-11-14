/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:44:08 by equentin          #+#    #+#             */
/*   Updated: 2025/11/14 16:16:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
%[format][width][precision]conv
*/
typedef struct s_format_list
{
	/*
	'#' adds 0x (0X for X) before val for x X conversion (for xX > 0)
	*/
	char		has_hex;
	/*
	pad with '0' instead of ' '
	ignored if '-' or precision secified for nb
	d i u x X only
	*/
	char		has_pad;
	/*
	'-' left align, space on right instead of left
	overrides '0'
	all conv
	*/
	char		has_lad; // '-'
	/*
	' ' adds ' ' before > 0 nb
	ignored if '+'
	d i only
	*/
	char		has_blk; // ' '
	/*
	'+' adds '+' sign for > 0 nb
	overrides ' '
	d i only
	*/
	char		has_sgn; // '+'
	/*
	'.'
	- d i u x X : nb of digits (pads with 0)
	- s : max nb of chars to print
	overrides '0'
	*/
	char		has_prs; // '.'
	/*
	min field width (pads with space or '0' if flag has_pad)
	all conv
	*/
	int			width;
	int			precision; // number of precision
	char		c; // conversion char
	size_t		new_index; // new index of i in the loop after parse
}				t_format_list;

t_format_list	*ft_get_format(const char *s);
int				ft_printf(const char *fmt, ...);
void			write_c(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			write_s(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			write_x(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			write_p(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			write_c(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			write_diu(t_format_list *fmt_lst, int	*printed, va_list *ap);
void			*format_pre_conv(t_format_list *fmt_lst, int *printed);
void			*format_post_conv(t_format_list *fmt_lst, int *printed);
char			*ft_itoa_u(unsigned int n);
void			ft_putnbr_hex(unsigned long nbr, char *base, int *printed);

#endif