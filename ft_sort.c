/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:50:54 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:50:57 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_number(int count, int location)
{
	int	min;

	if (count <= location)
		min = count;
	else
		min = location;
	return (min);
}

int	count_stack(t_node *stack_A)
{
	t_node	*current;
	int		count;

	count = 0;
	current = stack_A;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_sortin_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*courent_a;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	write(1, "pb\n", 3);
	courent_a = *stack_a;
	*stack_a = (*stack_a)->next;
	courent_a->next = NULL;
	*stack_b = ft_lstadd_front(*stack_b, courent_a);
}

void	ft_line(t_node **stack_b, t_node **new_stack)
{
	while (*stack_b != NULL)
	{
		*stack_b = ft_max_number(*stack_b);
		ft_comparision_stacka(*stack_b, new_stack);
		ft_sortin_a(stack_b, new_stack);
	}
}

t_node	*ft_sortin_stack_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*new_stack;
	int		count;

	count = 1;
	if (stack_a == NULL || stack_a->next == NULL)
		return (stack_a);
	ft_sortin_stack_b(&stack_a, &stack_b);
	ft_sortin_stack_b(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		count = count_stack(stack_a);
		if (count == 3)
		{
			stack_a = ft_swap(stack_a);
			break ;
		}
		ft_min_move(&stack_a, &stack_b);
		ft_comparision(stack_a, &stack_b);
		ft_sortin_stack_b(&stack_a, &stack_b);
	}
	new_stack = stack_a;
	ft_line(&stack_b, &new_stack);
	new_stack = min_number(new_stack);
	return (new_stack);
}
