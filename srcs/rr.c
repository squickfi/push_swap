/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:14:34 by squickfi          #+#    #+#             */
/*   Updated: 2021/08/18 20:14:37 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	if (!first || !first->next)
		return ;
	last = find_last_elem(first);
	first->next->previous = NULL;
	*list = first->next;
	first->previous = last;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **list)
{
	r(list);
	write(1, "ra\n", 3);
}

void	rb(t_list **list)
{
	r(list);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}
