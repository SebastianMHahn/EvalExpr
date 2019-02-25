/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_functions2.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 15:38:03 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/23 15:38:55 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

char		peek(t_list *begin_list)
{
	char	op;

	op = 'X';
	if (begin_list == 0)
		op = 'X';
	else
		op = begin_list->op;
	return (op);
}

t_list		*pop_stack(t_list **begin_list)
{
	t_list	*temp;

	temp = *begin_list;
	*begin_list = temp->next;
	return (temp);
}

char		pop_stack_c(t_list **begin_list)
{
	char	op;
	t_list	*temp;

	temp = *begin_list;
	*begin_list = temp->next;
	op = temp->op;
	free(temp);
	return (op);
}

int			pop_stack_i(t_list **begin_list)
{
	int		val;
	t_list	*temp;

	temp = *begin_list;
	*begin_list = temp->next;
	val = temp->val;
	free(temp);
	return (val);
}
