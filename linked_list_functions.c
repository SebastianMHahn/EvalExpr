/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_functions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 14:46:10 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/23 15:34:00 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

t_list	*ft_create_elem(int val, char op, int type)
{
	t_list	*temp;

	temp = 0;
	if ((temp = malloc(sizeof(t_list))) != 0)
	{
		temp->val = val;
		temp->op = op;
		temp->type = type;
		temp->next = 0;
	}
	return (temp);
}

void	push_front(t_list **begin_list, int val, char op, int type)
{
	t_list *temp;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(val, op, type);
		return ;
	}
	temp = ft_create_elem(val, op, type);
	temp->next = *begin_list;
	*begin_list = temp;
}

void	push_back(t_list **begin_list, int val, char op, int type)
{
	t_list *temp;
	t_list *list;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(val, op, type);
		return ;
	}
	list = *begin_list;
	temp = ft_create_elem(val, op, type);
	while (list->next != 0)
	{
		list = list->next;
	}
	list->next = temp;
}
