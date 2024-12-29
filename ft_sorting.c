/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:56:50 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:56:55 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_location(t_node **current_a, int *nb, long *target, int *check)
{
	if (*nb < *target)
	{
		*target = *nb;
		*check = (*current_a)->data;
	}
}

void	ft_move_min(int *location, int *index, t_node **stack_a,
		t_node **stack_b)
{
	if (*location > (count_stack(*stack_b) / 2))
		*location = count_stack(*stack_b) - *location + 1;
	if (*index > count_stack(*stack_a) / 2)
		*index = count_stack(*stack_a) - *index + 1;
}

int	ft_helper(t_node *stack_a, t_node *stack_b, int *index, int *location)
{
	int	nb;

	if ((ft_check_index(stack_a, stack_b, *index, *location)) == 1)
	{
		*location = count_stack(stack_b) - *location;
		*index = count_stack(stack_a) - *index + 1;
		nb = *index + *location - ft_min_number(*index, *location);
	}
	else if ((ft_check_index(stack_a, stack_b, *index, *location)) == 2)
		nb = *index + *location - ft_min_number(*index, *location);
	else
	{
		ft_move_min(location, index, &stack_a, &stack_b);
		nb = *index + *location;
	}
	return (nb);
}

int	ft_check_location(t_node *stack_a, t_node *stack_b, long target)
{
	int		check;
	int		nb;
	int		index;
	int		location;
	t_node	*current_a;

	ft_varible(&check, &index, &location);
	current_a = stack_a;
	while (current_a != NULL)
	{
		location = count_locatin(stack_b, ft_comparision_b(current_a, stack_b));
		index = count_locatin(stack_a, current_a->data);
		nb = ft_helper(stack_a, stack_b, &index, &location);
		if (nb < target)
			ft_location(&current_a, &nb, &target, &check);
		current_a = current_a->next;
	}
	return (check);
}

void	ft_min_move(t_node **stack_a, t_node **stack_b)
{
	int		result_a;
	long	target;
	int		result_b;
	int		count_a;
	int		count_b;

	target = LONG_MAX;
	if (*stack_a != NULL && *stack_b != NULL)
	{
		result_a = ft_check_location(*stack_a, *stack_b, target);
		result_b = ft_comp(result_a, *stack_b);
		count_a = count_locatin(*stack_a, result_a);
		count_b = count_locatin(*stack_b, result_b);
		if (count_a <= count_stack(*stack_a) / 2)
			ft_cheack_rr(stack_a, stack_b, count_a, count_b);
		else if (count_a > count_stack(*stack_a) / 2)
			ft_cheack_rrr(stack_a, stack_b, count_a, count_b);
	}
}
