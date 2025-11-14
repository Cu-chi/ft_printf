/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:13:48 by equentin          #+#    #+#             */
/*   Updated: 2025/11/14 16:12:26 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>
#include <stdio.h>

void	ft_putnbr_hex(unsigned long nbr, char *base, int *printed)
{
	if (nbr < 16)
	{
		write(1, base + nbr % 16, 1);
		(*printed)++;
		return ;
	}
	ft_putnbr_hex(nbr / 16, base, printed);
	ft_putnbr_hex(nbr % 16, base, printed);
}
