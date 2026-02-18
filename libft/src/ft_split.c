/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:07:33 by dfridlun          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:52 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/libft.h"
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c && in_word == 1)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**allocate_res(size_t word_count)
{
	char	**result;

	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (result)
		result[word_count] = NULL;
	return (result);
}

static void	free_result(char **result, size_t index)
{
	while (index--)
		free(result[index]);
	free(result);
}

static int	fill_result(char **result, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word;

	i = 0;
	start = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[word] = ft_substr(s, start, i - start);
			if (!result[word++])
			{
				free_result(result, word);
				return (0);
			}
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = allocate_res(word_count);
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}
