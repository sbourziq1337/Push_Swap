/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:34:59 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:35:07 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_node *result)
{
	t_node	*temp;

	while (result != NULL)
	{
		temp = result;
		result = result->next;
		free(temp);
	}
}

void	ft_free_stack(char **s, int nb)
{
	while (nb >= 0)
		free((s[nb--]));
	free(s);
}
