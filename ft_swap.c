/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:09:34 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 16:09:29 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_rotate_rra(t_node *swap)
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
	write(1, "rra\n", 4);
	return (new_head);
}

t_node	*ft_swap_a(t_node *swap)
{
	t_node	*ptr;
	int		temp;

	if (swap == NULL)
		return (NULL);
	ptr = swap;
	temp = ptr->next->data;
	ptr->next->data = ptr->data;
	ptr->data = temp;
	write(1, "sa\n", 3);
	return (swap);
}

void	ft_hypotheses_second(t_node **res, int *swappedd)
{
	if ((*res)->data < (*res)->next->next->data
		&& (*res)->next->data > (*res)->next->next->data)
	{
		*res = ft_swap_a(*res);
		*res = ft_rotate_ra(*res);
		*swappedd = 1;
	}
	else if (((*res)->data > (*res)->next->next->data)
		&& (*res)->next->data > (*res)->next->next->data)
	{
		*res = ft_rotate_rra(*res);
		*swappedd = 1;
	}
}

void	ft_hypotheses_frist(t_node **res, int *swappedd)
{
	if ((*res)->data < (*res)->next->next->data
		&& (*res)->next->data < (*res)->next->next->data)
	{
		*res = ft_swap_a(*res);
		*swappedd = 1;
	}
	else if ((*res)->data > (*res)->next->next->data
		&& (*res)->next->data > (*res)->next->next->data)
	{
		*res = ft_swap_a((*res));
		(*res) = ft_rotate_rra((*res));
		*swappedd = 1;
	}
	else if ((*res)->data > (*res)->next->next->data
		&& (*res)->next->data < (*res)->next->next->data)
	{
		(*res) = ft_rotate_ra((*res));
		*swappedd = 1;
	}
}

t_node	*ft_swap(t_node *swap)
{
	t_node	*res;
	int		swappedd;

	if (swap == NULL)
		return (swap);
	res = swap;
	swappedd = 1;
	while (swappedd)
	{
		swappedd = 0;
		if ((res->data > res->next->data))
			ft_hypotheses_frist(&res, &swappedd);
		else
			ft_hypotheses_second(&res, &swappedd);
	}
	res = min_number(res);
	return (res);
}
