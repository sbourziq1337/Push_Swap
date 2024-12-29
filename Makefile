SRC = ft_Comparison.c ft_atoi.c ft_checknull.c ft_check_sum_nb.c\
	  ft_count_stackA.c ft_free.c ft_max_number.c ft_double_rotate.c\
	  ft_node.c ft_rt.c ft_sort.c ft_sorting.c ft_split.c\
	  ft_swap.c ft_swap_stack_A.c ft_swap_stack_b.c push_swap.c

SRCB = checker_bonus.c ft_count_bonus.c ft_push_bonus.c ft_rotate_bonus.c\
   ft_same_char_bonus.c get_next_line.c get_next_line_utils.c ft_atoi.c\
   ft_node.c ft_split.c

OBJS= ${SRC:.c=.o}
OBJSB = ${SRCB:.c=.o}
NAME= push_swap
CHECKER = checker
RM = rm -f
CC = cc

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $?

bonus : ${CHECKER}

$(CHECKER) : $(OBJSB)
	$(CC) $^ -o $@

clean :
	${RM} ${OBJS} ${OBJSB}

fclean : clean
	${RM} ${NAME}

re: fclean all

.PHONY : all fclean clean re bonus
