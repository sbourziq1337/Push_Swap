/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:43:25 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/04 22:43:29 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char **words)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (words[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_check_split_null(char *av)
{
	char	**result;

	result = ft_split(av, ' ');
	if (result == NULL)
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	return (result);
}

t_node	*ft_check_four_nb(t_node *stack_b)
{
	t_node	*stack_newb;

	if (stack_b != NULL)
	{
		stack_b = min_number(stack_b);
		write(1, "pb\n", 3);
		stack_newb = stack_b->next;
		stack_b->next = ft_swap(stack_newb);
		write(1, "pa\n", 3);
	}
	return (stack_b);
}
