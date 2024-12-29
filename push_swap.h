/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:06:26 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 17:06:31 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

t_node				*ft_lstnew(int content);
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*ft_lstlast(t_node *lst);
char				**ft_split(char const *s, char c);
void				ft_checke_characters(char **check_letters, int ac, int j);
long				ft_atoi(char *str);
char				**ft_check_split_null(char *av);
void				ft_free_node(t_node *result);
t_node				*ft_node(int numbr, t_node *result);
void				ft_satack_a(int ac, char **av, t_node **stack_a);
int					count_words(char **words);
int					count_stacka(t_node *stack_A, int ac);
t_node				*ft_swap(t_node *head);
t_node				*ft_lstadd_front(t_node *lst, t_node *new);
t_node				*ft_swap_b(t_node *swap);
t_node				*ft_rotate_rra(t_node *swap);
t_node				*ft_rotate_ra(t_node *rotate);
t_node				*ft_sortin_stack_a(t_node *stack_a, t_node *stack_b);
void				ft_sortin_stack_b(t_node **stack_a, t_node **stack_b);
int					count_stack(t_node *stack_A);
void				ft_comparision(t_node *stack_a, t_node **stack_b);
int					ft_comparision_b(t_node *stack_a, t_node *stack_b);
int					count_locatin(t_node *stack_b, int nb);
int					ft_comparision_a(t_node *stack_a, t_node *stack_b);
t_node				*ft_rotate_rrb(t_node *swap);
t_node				*ft_rotate_rb(t_node *rotate);
void				ft_comparision_stacka(t_node *stack_a, t_node **stack_b);
void				ft_sortin_a(t_node **stack_a, t_node **stack_b);
t_node				*ft_check_sorting(t_node *stack_a);
int					ft_check_location(t_node *stack_a, t_node *stack_b,
						long target);
void				ft_min_move(t_node **stack_a, t_node **stack_b);
t_node				*ft_max_number(t_node *stack_b);
int					ft_max_nb(t_node *stack_b);
t_node				*ft_rra(t_node *swap);
t_node				*ft_ra(t_node *rotate);
int					ft_same_nb(t_node *stack_a);
t_node				*min_number(t_node *stack_b);
int					ft_min_nb(t_node *stack_b);
int					ft_sort(t_node *stack_a);
t_node				*ft_while(t_node *stack_b, int count, int nb);
t_node				*ft_moreline(t_node *stack_b, int count, int nb);
int					ft_min_number(int count, int location);
void				ft_cheack_rr(t_node **stack_a, t_node **stack_b,
						int count_a, int count_b);
void				ft_cheack_rrr(t_node **stack_a, t_node **stack_b,
						int count_a, int count_b);
void				ft_free_stack(char **s, int nb);
t_node				*ft_swap_a(t_node *swap);
void				ft_move_min(int *location, int *index, t_node **stack_a,
						t_node **stack_b);
t_node				*ft_check_four_nb(t_node *stack_b);
int					ft_check_index(t_node *stack_a, t_node *stack_b, int index,
						int location);
void				ft_varible(int *check, int *index, int *location);
int					ft_comp(int number, t_node *stack_b);
#endif
