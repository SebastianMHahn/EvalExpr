/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_header.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 14:47:04 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/23 14:51:55 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_HEADER_H
# define LINKED_LIST_HEADER_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	struct s_list	*next;
	int				val;
	char			op;
	int				type;
}					t_list;

void				handle_number(char	*str, t_list **tokenlist, int c[4]);
void				handle_operator(char *str, t_list **tokenlist, int c[4]);
t_list				*string_to_tokenlist(char *str);
void				handle_type_1(t_list **stack,
					t_list **postfix, t_list *temp);
t_list				*infix_to_postfix(t_list **token);
int					evaluate_postfix(t_list **postfix);
int					eval_expr(char *str);
t_list				*ft_create_elem(int val, char op, int type);
void				push_front(t_list **begin_list, int val, char op, int type);
void				push_back(t_list **begin_list, int val, char op, int type);
char				peek(t_list *begin_list);
t_list				*pop_stack(t_list **begin_list);
char				pop_stack_c(t_list **begin_list);
int					pop_stack_i(t_list **begin_list);
int					is_bracket(char c);
int					is_operator(char c);
int					apply_op(int a, int b, char op);
int					rank(char op1, char op2);
int					ft_atoi(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nbr);
#endif
