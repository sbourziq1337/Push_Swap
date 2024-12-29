/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:50:08 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:50:13 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_ra(t_node *rotate)
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

t_node	*ft_rra(t_node *swap)
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
