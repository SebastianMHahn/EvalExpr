/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_to_tokenlist.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 09:47:30 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/24 09:47:34 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_header.h"

void		handle_number(char *str, t_list **tokenlist, int c[4])
{
	char		numstr[20];

	c[1] = 0;
	while (str[c[0]] >= '0' && str[c[0]] <= '9')
	{
		numstr[0 + c[1]] = str[c[0]];
		c[0]++;
		c[1]++;
	}
	numstr[c[1]] = '\0';
	push_back(tokenlist, c[2] * ft_atoi(numstr), 'N', 0);
	c[2] = 1;
	c[3] = 0;
}

void		handle_operator(char *str, t_list **tokenlist, int c[4])
{
	if (is_operator(str[c[0]]) == 1)
		c[3]++;
	if (str[c[0]] == '-' && c[3] == 2)
	{
		c[2] = -1;
		c[3] = 0;
	}
	else
		push_back(tokenlist, -1, str[c[0]], 1);
	c[0]++;
}

t_list		*string_to_tokenlist(char *str)
{
	int			c[4];
	t_list		*tokenlist;

	c[0] = 0;
	c[2] = 1;
	c[3] = 1;
	tokenlist = 0;
	while (str[c[0]] != '\0')
	{
		if (str[c[0]] >= '0' && str[c[0]] <= '9')
			handle_number(str, &tokenlist, c);
		else if (is_operator(str[c[0]]) == 1 || is_bracket(str[c[0]]) == 1)
			handle_operator(str, &tokenlist, c);
		else
			c[0]++;
	}
	return (tokenlist);
}
