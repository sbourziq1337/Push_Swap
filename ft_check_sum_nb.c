/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sum_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:27:11 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/04 21:30:32 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_node *stack_a)
{
	if (stack_a == 0)
		exit (1);
	while (stack_a->next != NULL)
	{
		if (stack_a->data < stack_a->next->data)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_same_nb(t_node *stack_a)
{
	t_node	*new_node;

	new_node = stack_a;
	while (stack_a != NULL)
	{
		while (stack_a->next != NULL)
		{
			if (new_node->data == stack_a->next->data)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			stack_a = stack_a->next;
		}
		new_node = new_node->next;
		stack_a = new_node;
	}
	return (0);
}

int	ft_min_nb(t_node *stack_b)
{
	int	target;

	target = INT_MAX;
	while (stack_b != NULL)
	{
		if (stack_b->data < target)
		{
			target = stack_b->data;
		}
		stack_b = stack_b->next;
	}
	return (target);
}

t_node	*ft_while(t_node *stack_b, int count, int nb)
{
	if (count <= nb && count > 1)
	{
		while (count > 1)
		{
			stack_b = ft_rotate_ra(stack_b);
			count--;
		}
	}
	else if (count > nb)
	{
		while (count <= (count_stack(stack_b)))
		{
			stack_b = ft_rotate_rra(stack_b);
			count++;
		}
	}
	return (stack_b);
}

t_node	*min_number(t_node *stack_b)
{
	t_node	*stack_newb;
	int		result_a;
	int		result_b;
	int		count;
	int		nb;

	count = 0;
	nb = 0;
	result_a = 0;
	result_b = 0;
	stack_newb = NULL;
	if (stack_b != NULL)
	{
		result_a = ft_min_nb(stack_b);
		count = count_locatin(stack_b, result_a);
		if (count == 1)
			return (stack_b);
		nb = (count_stack(stack_b) / 2);
		stack_b = ft_while(stack_b, count, nb);
	}
	return (stack_b);
}
