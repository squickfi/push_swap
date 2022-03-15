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

void	r_r(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	if (!first || !first->next)
		return ;
	last = find_last_elem(first);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	*list = last;
}

void	rra(t_list **list)
{
	r_r(list);
	write(1, "rra\n", 4);
}

void	rrb(t_list **list)
{
	r_r(list);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	r_r(a);
	r_r(b);
	write(1, "rrr\n", 4);
}
