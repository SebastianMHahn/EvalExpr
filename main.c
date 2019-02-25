/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 15:34:17 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/23 15:38:20 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

int			eval_expr(char *str)
{
	int		result;
	t_list	*tokenlist;
	t_list	*postfix;

	result = 0;
	tokenlist = string_to_tokenlist(str);
	postfix = infix_to_postfix(&tokenlist);
	result = evaluate_postfix(&postfix);
	return (result);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
