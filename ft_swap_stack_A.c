/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack_A.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:00:05 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 10:00:11 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortin_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*courent_a;

	write(1, "pa\n", 3);
	courent_a = *stack_b;
	*stack_b = (*stack_b)->next;
	courent_a->next = NULL;
	*stack_a = ft_lstadd_front(*stack_a, courent_a);
}

int	ft_comparision_a(t_node *stack_b, t_node *stack_a)
{
	int	target;

	target = INT_MAX;
	if (stack_a == NULL)
		return (INT_MAX);
	while (stack_a != NULL)
	{
		if (stack_b->data < stack_a->data && stack_a->data < target)
		{
			target = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	if (target == INT_MAX)
		target = ft_max_nb(stack_b);
	return (target);
}

void	ft_comparision_stacka(t_node *stack_b, t_node **stack_a)
{
	int	count;

	count = 0;
	if (stack_a != NULL)
	{
		if (ft_comparision_a(stack_b, *stack_a) == INT_MAX)
			return ;
		count = count_locatin(*stack_a, ft_comparision_a(stack_b, *stack_a));
		if (count <= (count_stack(*stack_a) / 2) && count > 1)
		{
			while (count > 1)
			{
				*stack_a = ft_rotate_ra(*stack_a);
				count--;
			}
		}
		else if (count > (count_stack(*stack_a) / 2))
		{
			while (count <= (count_stack(*stack_a)))
			{
				*stack_a = ft_rotate_rra(*stack_a);
				count++;
			}
		}
	}
}
