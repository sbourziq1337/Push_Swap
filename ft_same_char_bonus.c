/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_same_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:39:50 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:39:54 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_char(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ptr[i])
			i++;
		else
			return (0);
	}
	return (1);
}

t_node	*ft_swap_sa(t_node *swap)
{
	t_node	*ptr;
	int		temp;

	if (swap == NULL)
		return (NULL);
	ptr = swap;
	temp = ptr->next->data;
	ptr->next->data = ptr->data;
	ptr->data = temp;
	return (swap);
}

int	ft_sort(t_node *stack_a)
{
	if (stack_a == NULL)
		exit(1);
	while (stack_a->next != NULL)
	{
		if (stack_a->data < stack_a->next->data)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}
