/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:29:25 by sbourziq          #+#    #+#             */
/*   Updated: 2024/01/14 13:29:40 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checke_characters(char **check_letters, int ac, int j)
{
	int	n;

	while (j < ac)
	{
		n = 0;
		while (check_letters[j][n] != '\0')
		{
			if (!((check_letters[j][n] == ' ') || (check_letters[j][n] >= 9
				&& check_letters[j][n] <= 13))
				&& !(check_letters[j][n] >= '0' && check_letters[j][n] <= '9')
				&& !(check_letters[j][n] == '-' || check_letters[j][n] == '+'))
			{
				write(1, "Erorr\n", 6);
				exit(1);
			}
			n++;
		}
		if (check_letters[j][0] == '\0')
		{
			write(1, "Erorr\n", 6);
			exit(1);
		}
		j++;
	}
}

void	ft_check_negtive(char **str, long *i, long *check)
{
	long	j;

	j = *i;
	if ((*str)[j] == '-')
		(*check)++;
	(*i)++;
}

void	ft_erorr(char **str, long *i)
{
	long	j;

	j = *i;
	if ((*str)[j] == '-' || (*str)[j] == '+')
	{
		write(1, "Erorr\n", 6);
		exit(1);
	}
}

void	ft_print_erorre(char *str)
{
	if (str != NULL)
	{
		write(1, "Erorr\n", 6);
		exit(1);
	}
}

long	ft_atoi(char *str)
{
	long	i;
	long	number;
	long	check;

	i = 0;
	number = 0;
	check = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0'
				&& str[i + 1] <= '9'))
			ft_check_negtive(&str, &i, &check);
		while (str[i] >= '0' && str[i] <= '9')
			number = number * 10 + (str[i++] - 48);
		if (str[i] == '-' || str[i] == '+')
			ft_erorr(&str, &i);
		if (number > INT_MAX)
			ft_print_erorre(str);
		if (check % 2 == 0)
			return (number);
		return (-number);
	}
	return (number);
}
