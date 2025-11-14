/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:23:49 by equentin          #+#    #+#             */
/*   Updated: 2025/11/14 16:31:18 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	*format_pre_conv(t_format_list *fmt_lst, int *printed)
{
	if (fmt_lst->has_sgn && (fmt_lst->c == 'd' || fmt_lst->c == 'i'
			|| fmt_lst->c == 'u'))
	{
		return (NULL);
	}
	if (fmt_lst->has_hex && (fmt_lst->c == 'x' || fmt_lst->c == 'X'
			|| fmt_lst->c == 'p'))
	{
		if (fmt_lst->c == 'x' || fmt_lst->c == 'p')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		*printed += 2;
	}
	return (NULL);
}

void	*format_post_conv(t_format_list *fmt_lst, int *printed)
{
	(void)fmt_lst;
	(void)printed;
	return (NULL);
}
