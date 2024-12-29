/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:21:39 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:21:44 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
