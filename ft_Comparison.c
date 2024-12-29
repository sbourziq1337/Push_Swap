/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Comparison.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:44:13 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/04 22:44:20 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_locatin(t_node *stack_b, int nb)
{
	t_node	*current;
	int		count;

	count = 1;
	current = stack_b;
	while (current != NULL)
	{
		if (current->data == nb)
			return (count);
		count++;
		current = current->next;
	}
	return (-1);
}

int	ft_comparision_b(t_node *stack_a, t_node *stack_b)
{
	long	target;

	target = LONG_MIN;
	if (stack_b == NULL)
		return (target);
	while (stack_b != NULL)
	{
		if (stack_a->data > stack_b->data && stack_b->data > target)
		{
			target = stack_b->data;
		}
		stack_b = stack_b->next;
	}
	if (target == LONG_MIN)
		target = ft_max_nb(stack_b);
	return (target);
}

t_node	*ft_moreline(t_node *stack_b, int count, int nb)
{
	if (count < nb && count > 1)
	{
		while (count > 1)
		{
			stack_b = ft_rotate_rb(stack_b);
			count--;
		}
	}
	else if (count >= nb)
	{
		while (count <= (count_stack(stack_b)))
		{
			stack_b = ft_rotate_rrb(stack_b);
			count++;
		}
	}
	return (stack_b);
}

void	ft_comparision(t_node *stack_a, t_node **stack_b)
{
	long	result;
	int		count;
	int		nb;

	count = 0;
	nb = 0;
	result = 0;
	if (stack_a != NULL)
	{
		result = ft_comparision_b(stack_a, *stack_b);
		if (result == LONG_MIN)
			return ;
		count = count_locatin(*stack_b, result);
		nb = ((count_stack(*stack_b) / 2));
		*stack_b = ft_moreline(*stack_b, count, nb);
	}
}
