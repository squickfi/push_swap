/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:14:15 by squickfi          #+#    #+#             */
/*   Updated: 2021/08/18 20:14:23 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	parse_args(&stack_a, argc, argv);
	if (check_if_args_are_right(&stack_a))
		return (0);
	presort_list(&stack_a, argc);
	if (argc == 3 && stack_a->num > stack_a->next->num)
		sa(&stack_a);
	else if (argc == 4)
		sort_3_numbers(&stack_a);
	else if (argc == 5)
		sort_4_numbers(&stack_a, &stack_b);
	else if (argc == 6)
		sort_5_numbers(&stack_a, &stack_b);
	else
		sort_list(&stack_a, &stack_b, argc);
	if (argc > 1)
		free_list(&stack_a), free_list(&stack_b);
	return (0);
}
