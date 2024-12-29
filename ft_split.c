/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:58:13 by sbourziq          #+#    #+#             */
/*   Updated: 2024/02/05 09:58:19 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *str, int start, int len)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = malloc((len + 1) * (sizeof(char)));
	if (str == NULL || ptr == NULL)
		return (free(ptr), NULL);
	while (str[start] != '\0' && count < len)
		ptr[count++] = str[start++];
	ptr[count] = '\0';
	return (ptr);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static char	**ft_free(char **s, int nb)
{
	while (nb > 0)
		free((s[nb--]));
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**result;

	i = 0;
	n = 0;
	result = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (result == NULL || s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\0' && j++ >= -1)
			i++;
		result[n++] = ft_substr(s, i - j, j);
		if (result[n - 1] == NULL)
			return (ft_free(result, n - 1));
	}
	result[n] = NULL;
	return (result);
}
