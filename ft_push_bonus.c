/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:38:35 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:38:39 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*courent_a;

	if (*stack_a == NULL)
		return ;
	courent_a = *stack_a;
	*stack_a = (*stack_a)->next;
	courent_a->next = NULL;
	*stack_b = ft_lstadd_front(*stack_b, courent_a);
}

void	push_stack_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*courent_a;

	if (*stack_b == NULL)
		return ;
	courent_a = *stack_b;
	*stack_b = (*stack_b)->next;
	courent_a->next = NULL;
	*stack_a = ft_lstadd_front(*stack_a, courent_a);
}
