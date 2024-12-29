/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:08:27 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 10:08:33 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_rotate_rrb(t_node *swap)
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
	write(1, "rrb\n", 4);
	return (new_head);
}

t_node	*ft_rotate_rb(t_node *rotate)
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
	write(1, "rb\n", 3);
	return (head_new);
}
