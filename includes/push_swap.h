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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_info
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}	t_info;

/*
quick_sort.c
*/

void	sort_3_numbers(t_list **a);
void	sort_4_numbers_additional_func(t_list **a, t_list **b);
void	sort_5_numbers_additional_func(t_list **a, t_list **b);
void	sort_4_numbers(t_list **a, t_list **b);
void	sort_5_numbers(t_list **a, t_list **b);

/*
work_with_lists.c
*/

// void	print_list(t_list *a); // temp_function
t_list	*create_list(int num);
void	free_list(t_list **list);
void	ft_push_front(t_list **a, int num);
t_list	*find_last_elem(t_list *list);

/*
parse_args.c
*/

void	an_error_was_found(t_list **a);
int		ft_push_swap_atoi(t_list **a, char *str);
void	parse_args(t_list **a, int argc, char **argv);
int		check_if_args_are_right(t_list **a);

/*
ss.c
*/

void	s(t_list **list);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

/*
pa_pb.c
*/

void	p(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

/*
rr.c
*/

void	r(t_list **list);
void	ra(t_list **list);
void	rb(t_list **list);
void	rr(t_list **a, t_list **b);

/*
rrr.c
*/

void	r_r(t_list **list);
void	rra(t_list **list);
void	rrb(t_list **list);
void	rrr(t_list **a, t_list **b);

/*
sort_lists.c
*/

int		is_list_sorted(t_list **a, t_list **b);
int		is_list_sorted2(t_list **a);
int		find_max(t_list **a);

/*
sort_lists2.c
*/

void	presort_list(t_list **a, int argc);
t_info	*init_info(int argc);
void	sort_list(t_list **a, t_list **b, int argc);

/*
sort_lists3.c
*/

void	first_iteration(t_list **a, t_list **b, t_info *info);
void	right_to_left_cycle(t_list **a, t_list **b, t_info *info);
void	right_to_left(t_list **a, t_list **b, t_info *info);
void	left_to_right_cycle(t_list **a, t_list **b, t_info *info);
void	left_to_right(t_list **a, t_list **b, t_info *info);

#endif
