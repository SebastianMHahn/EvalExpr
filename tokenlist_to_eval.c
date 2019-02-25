/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenlist_to_eval.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 10:12:36 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/24 10:12:40 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

void		handle_type_1(t_list **stack, t_list **postfix, t_list *temp)
{
	if (peek(temp) == '(')
	{
		push_front(stack, -1, '(', 0);
	}
	else if (peek(temp) == ')')
	{
		while (peek(*stack) != 'X' && peek(*stack) != '(')
			push_back(postfix, -1, pop_stack_c(stack), 1);
		if (peek(*stack) == '(')
			pop_stack(stack);
	}
	else if (peek(*stack) == 'X' || peek(*stack) == '(')
	{
		push_front(stack, -1, temp->op, 1);
	}
	else
	{
		while (peek(*stack) != 'X' && peek(*stack) != '(' &&
		rank(peek(temp), peek(*stack)) <= 0)
			push_back(postfix, -1, pop_stack_c(stack), 1);
		push_front(stack, -1, temp->op, 1);
	}
}

t_list		*infix_to_postfix(t_list **token)
{
	t_list	*stack;
	t_list	*postfix;
	t_list	*temp;

	stack = 0;
	postfix = 0;
	while (*token != 0)
	{
		temp = pop_stack(token);
		if (temp != 0)
		{
			if (temp->type == 0)
				push_back(&postfix, temp->val, 'N', 0);
			else
				handle_type_1(&stack, &postfix, temp);
			free(temp);
		}
	}
	while (stack != 0)
		push_back(&postfix, -1, pop_stack_c(&stack), 1);
	return (postfix);
}

int			evaluate_postfix(t_list **postfix)
{
	t_list	*stack;
	t_list	*temp;
	int		a;
	int		b;
	int		result;

	stack = 0;
	while (*postfix != 0)
	{
		temp = pop_stack(postfix);
		if (temp->type == 0)
			push_front(&stack, temp->val, 'N', 0);
		else
		{
			a = pop_stack_i(&stack);
			b = pop_stack_i(&stack);
			result = apply_op(b, a, temp->op);
			push_front(&stack, result, 'N', 0);
		}
		free(temp);
	}
	result = pop_stack_i(&stack);
	return (result);
}
