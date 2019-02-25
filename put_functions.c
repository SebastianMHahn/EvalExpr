/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 20:07:31 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/23 20:07:32 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long num;

	num = nb;
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
	}
	if (num / 10 >= 1)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar('0' + (num % 10));
}
