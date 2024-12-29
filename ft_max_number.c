/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:36:34 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:36:41 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_nb(t_node *stack_b)
{
	int	target;

	target = INT_MIN;
	while (stack_b != NULL)
	{
		if (stack_b->data > target)
		{
			target = stack_b->data;
		}
		stack_b = stack_b->next;
	}
	return (target);
}

t_node	*ft_max_number(t_node *stack_b)
{
	int	count;

	count = 0;
	if (stack_b != NULL)
	{
		count = count_locatin(stack_b, ft_max_nb(stack_b));
		if (count <= (count_stack(stack_b) / 2) && count > 1)
		{
			while (count > 1)
			{
				stack_b = ft_rotate_rb(stack_b);
				count--;
			}
		}
		else if (count > (count_stack(stack_b) / 2))
		{
			while (count <= (count_stack(stack_b)))
			{
				stack_b = ft_rotate_rrb(stack_b);
				count++;
			}
		}
	}
	return (stack_b);
}
