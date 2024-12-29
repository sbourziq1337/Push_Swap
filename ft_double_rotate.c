/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:12 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:43:16 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheack_rr(t_node **stack_a, t_node **stack_b, int count_a,
		int count_b)
{
	while (count_a > 1 && count_b > 1 && count_b <= count_stack(*stack_b) / 2)
	{
		*stack_a = ft_ra(*stack_a);
		*stack_b = ft_ra(*stack_b);
		write(1, "rr\n", 3);
		count_a--;
		count_b--;
	}
	while (count_a > 1)
	{
		*stack_a = ft_rotate_ra(*stack_a);
		count_a--;
	}
}

void	ft_cheack_rrr(t_node **stack_a, t_node **stack_b, int count_a,
		int count_b)
{
	while (count_a <= count_stack(*stack_a) && count_b <= count_stack(*stack_b)
		&& count_b > count_stack(*stack_b) / 2)
	{
		*stack_a = ft_rra(*stack_a);
		*stack_b = ft_rra(*stack_b);
		write(1, "rrr\n", 4);
		count_a++;
		count_b++;
	}
	while (count_a <= count_stack(*stack_a))
	{
		*stack_a = ft_rotate_rra(*stack_a);
		count_a++;
	}
}
