/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:30 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:22:33 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_node	*ft_rot_ra(t_node *rotate)
{
	t_node	*head1;
	t_node	*head_new;

	if (rotate == NULL || rotate->next == NULL)
		return (rotate);
	head1 = rotate;
	head_new = rotate->next;
	while (head1->next != NULL)
		head1 = head1->next;
	head1->next = rotate;
	head1->next->next = NULL;
	rotate = head_new;
	return (head_new);
}

t_node	*ft_rot_rra(t_node *swap)
{
	t_node	*result;
	t_node	*new_head;

	if (swap == NULL || swap->next == NULL)
		return (swap);
	result = swap;
	new_head = swap->next;
	while (result->next != NULL)
	{
		if (result->next->next == NULL)
		{
			result->next->next = swap;
			new_head = result->next;
			result->next = NULL;
			break ;
		}
		result = result->next;
	}
	return (new_head);
}

void	ft_rot_rrr(t_node **stack_a, t_node **stack_b)
{
	*stack_a = ft_rot_rra(*stack_a);
	*stack_b = ft_rot_rra(*stack_b);
}

void	ft_rot_rr(t_node **stack_a, t_node **stack_b)
{
	*stack_a = ft_rot_ra(*stack_a);
	*stack_b = ft_rot_ra(*stack_b);
}
