/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sehahn <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 15:49:40 by sehahn        #+#    #+#                 */
/*   Updated: 2019/02/24 10:31:12 by sehahn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		apply_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	if (op == '*')
		return (a * b);
	else
		return (-999999999);
}

int		rank(char op1, char op2)
{
	int rank1;
	int rank2;

	if (op1 == '*' || op1 == '/' || op1 == '%')
		rank1 = 1;
	else
		rank1 = 0;
	if (op2 == '*' || op2 == '/' || op2 == '%')
		rank2 = 1;
	else
		rank2 = 0;
	return (rank1 - rank2);
}

int		is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	else
		return (0);
}

int		is_bracket(char c)
{
	if (c == '(' || c == ')')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int num;
	int i;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v') ||
(*str == '\f') || (*str == '\r') || (*str == ' '))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (int)(*str - '0');
		str++;
	}
	return (num * sign);
}
