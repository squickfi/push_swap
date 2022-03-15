/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:13:26 by squickfi          #+#    #+#             */
/*   Updated: 2021/08/18 20:13:28 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_list(t_list **a, int argc)
{
	t_list	*list;
	t_list	*temp;
	int		max;

	argc--;
	while (argc)
	{
		list = *a;
		max = -2147483648;
		while (list)
		{
			if (!list->order && list->num >= max)
			{
				temp = list;
				max = list->num;
			}
			list = list->next;
		}
		temp->order = argc;
		argc--;
	}
}

t_info	*init_info(int argc)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		exit(1);
	info->next = 1;
	info->max = argc - 1;
	info->mid = (info->max / 2) + info->next;
	info->flag = 0;
	return (info);
}

void	sort_list(t_list **a, t_list **b, int argc)
{
	t_info	*info;

	info = init_info(argc);
	first_iteration(a, b, info);
	while (!is_list_sorted(a, b))
	{
		info->mid = find_max(b);
		while (*b)
			right_to_left(a, b, info);
		if (!is_list_sorted2(a))
			left_to_right(a, b, info);
	}
	free(info);
}
