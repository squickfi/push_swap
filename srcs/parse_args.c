/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:14:00 by squickfi          #+#    #+#             */
/*   Updated: 2021/08/18 20:14:03 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	an_error_was_found(t_list **a)
{
	write(1, "Error\n", 6);
	free_list(a);
	exit(1);
}

int	ft_push_swap_atoi(t_list **a, char *str)
{
	size_t	count;
	int		sign;

	count = 0;
	sign = 0;
	if (*str == '-')
		sign = 1, str++;
	if (!*str)
		an_error_was_found(a);
	while (*str >= '0' && *str <= '9')
	{
		count *= 10;
		count += *str - '0';
		if ((sign && count > 2147483648) || (!sign && count > 2147483647))
			an_error_was_found(a);
		str++;
	}
	if (*str)
		an_error_was_found(a);
	if (sign)
		return (-count);
	return (count);
}

void	parse_args(t_list **a, int argc, char **argv)
{
	argc--;
	while (argc > 0)
		ft_push_front(a, ft_push_swap_atoi(a, argv[argc--]));
}

int	check_if_args_are_right(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;
	int		sorted;

	temp1 = *a;
	sorted = 1;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (sorted && temp2->num < temp1->num)
				sorted = 0;
			if (temp1->num == temp2->num)
				an_error_was_found(a);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (sorted);
}
