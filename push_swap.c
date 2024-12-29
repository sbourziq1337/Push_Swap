/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:38:42 by sbourziq          #+#    #+#             */
/*   Updated: 2024/01/10 18:38:57 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_rotate_ra(t_node *rotate)
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
	write(1, "ra\n", 3);
	return (head_new);
}

void	ft_satack_a(int ac, char **av, t_node **stack_a)
{
	int	check;
	int	i;
	int	numbr;

	i = 1;
	check = 0;
	if (ac == 2)
	{
		av = ft_check_split_null(av[1]);
		ac = count_words(av);
		i = 0;
		check = 1;
	}
	ft_checke_characters(av, ac, i);
	while (i < ac)
	{
		numbr = ft_atoi(av[i++]);
		*stack_a = ft_node(numbr, *stack_a);
	}
	if (check == 1)
		ft_free_stack(av, i);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	ft_satack_a(argc, argv, &stack_a);
	argc = count_stacka(stack_a, argc);
	if (ft_same_nb(stack_a) == 1 || ft_sort(stack_a) == 1)
	{
		ft_free_node(stack_a);
		exit(1);
	}
	if (argc == 3)
		stack_a = ft_swap(stack_a);
	if (argc == 4)
		stack_a = ft_check_four_nb(stack_a);
	if (argc == 2)
	{
		if (stack_a->data > stack_a->next->data)
			stack_a = ft_swap_a(stack_a);
	}
	else if (argc > 4)
		stack_a = ft_sortin_stack_a(stack_a, stack_b);
	ft_free_node(stack_a);
	return (0);
}
