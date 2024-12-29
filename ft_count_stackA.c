/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_stackA.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:32:13 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:32:17 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stacka(t_node *stack_A, int ac)
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
	if (ac == 1)
		return (count + 1);
	return (count);
}

int	ft_check_index(t_node *stack_a, t_node *stack_b, int index, int location)
{
	if (location > (count_stack(stack_b) / 2) && index > count_stack(stack_a)
		/ 2)
		return (1);
	else if ((location <= (count_stack(stack_b) / 2)
			&& index <= count_stack(stack_a) / 2))
		return (2);
	return (0);
}

void	ft_varible(int *check, int *index, int *location)
{
	*check = 0;
	*index = 0;
	*location = 1;
}

int	ft_comp(int number, t_node *stack_b)
{
	long	target;

	if (stack_b == NULL)
		return (-1);
	target = LONG_MIN;
	while (stack_b != NULL)
	{
		if (number > stack_b->data && stack_b->data > target)
		{
			target = stack_b->data;
		}
		stack_b = stack_b->next;
	}
	if (target == LONG_MIN)
		target = ft_max_nb(stack_b);
	return (target);
}
