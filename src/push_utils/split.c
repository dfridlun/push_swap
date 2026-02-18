/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:33:37 by dfridlun          #+#    #+#             */
/*   Updated: 2025/02/19 20:24:30 by dfridlun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

static size_t	count_words(const char *s, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*s)
	{
		in_word = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*next_word(char *s, char c, int *index)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[*index] == c)
		(*index)++;
	while (s[*index + len] && s[*index + len] != c)
		len++;
	next_word = (char *)ft_calloc((size_t)len + 1, sizeof(char));
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*index)++];
	next_word[i] = '\0';
	return (next_word);
}

static void	free_memory(char **result, int i)
{
	while (i >= 0)
		free(result[i]);
	free(result);
}

char	**split(char *s, char c)
{
	char	**result;
	int		word_count;
	int		i;
	int		index;

	index = 0;
	i = 0;
	word_count = count_words(s, c);
	if (!word_count)
		return (NULL);
	result = (char **)ft_calloc((size_t)(word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i < word_count)
	{
		result[i] = next_word(s, c, &index);
		if (!result[i])
		{
			free_memory(result, i - 1);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
