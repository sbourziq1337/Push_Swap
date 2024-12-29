/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:21:00 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:21:07 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_same_nb(t_node *stack_a)
{
	t_node	*new_node;

	new_node = stack_a;
	while (stack_a != NULL)
	{
		while (stack_a->next != NULL)
		{
			if (new_node->data == stack_a->next->data)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			stack_a = stack_a->next;
		}
		new_node = new_node->next;
		stack_a = new_node;
	}
	return (0);
}

void	ft_satack_a(int ac, char **av, t_node **stack_a)
{
	int	i;
	int	numbr;
	int	check;

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

void	ft_check_move2(t_node **stack_a, t_node **stack_b)
{
	write(2, "Error\n", 6);
	ft_free_node(*stack_a);
	ft_free_node(*stack_b);
	exit(1);
}

void	ft_check_move(char **str, t_node **stack_a, t_node **stack_b)
{
	if (ft_char(*str, "ra\n") == 1)
		*stack_a = ft_rot_ra(*stack_a);
	else if (ft_char(*str, "rra\n") == 1)
		*stack_a = ft_rot_rra(*stack_a);
	else if (ft_char(*str, "sa\n") == 1)
		*stack_a = ft_swap_sa(*stack_a);
	else if (ft_char(*str, "pb\n") == 1)
		push_stack_b(stack_a, stack_b);
	else if (ft_char(*str, "rb\n") == 1)
		*stack_b = ft_rot_rra(*stack_b);
	else if (ft_char(*str, "rrb\n") == 1)
		*stack_b = ft_rot_rra(*stack_b);
	else if (ft_char(*str, "sb\n") == 1)
		*stack_b = ft_swap_sa(*stack_b);
	else if (ft_char(*str, "pa\n") == 1)
		push_stack_a(stack_b, stack_a);
	else if (ft_char(*str, "rr\n") == 1)
		ft_rot_rr(stack_a, stack_b);
	else if (ft_char(*str, "rrr\n") == 1)
		ft_rot_rrr(stack_a, stack_b);
	else
		ft_check_move2(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	*str;
	t_node	*stack_b;

	ft_satack_a(argc, argv, &stack_a);
	argc = count_stacka(stack_a, argc);
	if (ft_same_nb(stack_a) == 1 || ft_sort(stack_a) == 1)
	{
		if (ft_sort(stack_a) == 1)
			write(1, "OK\n", 3);
		ft_free_node(stack_a);
		exit(1);
	}
	str = get_next_line(0);
	while (str != NULL)
	{
		ft_check_move(&str, &stack_a, &stack_b);
		str = get_next_line(0);
	}
	if (ft_sort(stack_a) == 1 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_node(stack_a);
	return (0);
}
