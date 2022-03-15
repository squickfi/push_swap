/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:12:58 by squickfi          #+#    #+#             */
/*   Updated: 2021/08/18 20:13:05 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_numbers(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if (temp->num < temp->next->num && temp->num < temp->next->next->num)
		sa(a), ra(a);
	else if (temp->num > temp->next->num && temp->num > temp->next->next->num)
	{
		if (temp->next->num < temp->next->next->num)
			ra(a);
		else
			sa(a), rra(a);
	}
	else
	{
		if (temp->next->num < temp->next->next->num)
			sa(a);
		else
			rra(a);
	}
}

void	sort_4_numbers_additional_func(t_list **a, t_list **b)
{
	t_list	*a_temp;
	t_list	*b_temp;

	a_temp = *a;
	b_temp = *b;
	if (a_temp->num > b_temp->num)
		pa(a, b);
	else if (a_temp->num < b_temp->num && a_temp->next->num > b_temp->num)
		pa(a, b), sa(a);
	else if (a_temp->next->num < b_temp->num && \
			a_temp->next->next->num > b_temp->num)
		ra(a), pa(a, b), sa(a), rra(a);
	else if (a_temp->next->next->num < b_temp->num)
		pa(a, b), ra(a);
}

void	sort_5_numbers_additional_func(t_list **a, t_list **b)
{
	t_list	*a_temp;
	t_list	*b_temp;

	a_temp = *a;
	b_temp = *b;
	if (a_temp->order - b_temp->order == 1)
		pa(a, b);
	else if (a_temp->order - b_temp->order == -1)
		pa(a, b), sa(a);
	else if (a_temp->next->order - b_temp->order == -1)
		ra(a), pa(a, b), sa(a), rra(a);
	else if (a_temp->next->next->order - b_temp->order == -1)
		rra(a), pa(a, b), ra(a), ra(a);
	else if (a_temp->next->next->next->order - b_temp->order == -1)
		pa(a, b), ra(a);
}

void	sort_4_numbers(t_list **a, t_list **b)
{
	pb(a, b);
	sort_3_numbers(a);
	sort_4_numbers_additional_func(a, b);
}

void	sort_5_numbers(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	sort_3_numbers(a);
	sort_4_numbers_additional_func(a, b);
	sort_5_numbers_additional_func(a, b);
}
