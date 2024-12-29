/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:21:18 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/09 17:21:25 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

ssize_t				ft_strlen(char *s);
char				*ft_substr(char *s, int start, int end);
char				*ft_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);
int					ft_checkline(char *str);
char				*ft_readfile(int fd);
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

void				ft_satack_a(int ac, char **av, t_node **stack_a);
int					count_stacka(t_node *stack_A, int ac);
int					ft_same_nb(t_node *stack_a);
int					ft_sort(t_node *stack_a);
void				ft_free_node(t_node *result);
t_node				*ft_lstnew(int content);
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*ft_lstlast(t_node *lst);
char				**ft_split(char const *s, char c);
void				ft_checke_characters(char **check_letters, int ac, int j);
long				ft_atoi(char *str);
char				**ft_check_split_null(char *av);
int					count_words(char **words);
void				ft_checke_characters(char **check_letters, int ac, int j);
t_node				*ft_node(int numbr, t_node *result);
t_node				*ft_lstnew(int content);
void				ft_free_stack(char **s, int nb);
t_node				*ft_rot_ra(t_node *rotate);
int					ft_char(char *str, char *ptr);
t_node				*ft_rot_rra(t_node *swap);
t_node				*ft_swap_sa(t_node *swap);
void				push_stack_b(t_node **stack_a, t_node **stack_b);
t_node				*ft_lstadd_front(t_node *lst, t_node *new);
void				push_stack_a(t_node **stack_b, t_node **stack_a);
void				ft_rot_rr(t_node **stack_a, t_node **stack_b);
void				ft_rot_rrr(t_node **stack_a, t_node **stack_b);

#endif
