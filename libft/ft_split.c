/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:53:37 by stak              #+#    #+#             */
/*   Updated: 2023/11/22 15:18:38 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != 0)
		{
			count++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		while (s[i] == c && s[i] != 0)
			i++;
	}
	return (count);
}

static char	**ft_free(char **result, size_t j)
{
	while (j > 0)
	{
		free(result[j - 1]);
		j--;
	}
	free (result);
	return (NULL);
}

static char	**ft_strwordcount(char const *s, char c, char **string)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			string[j] = ft_substr(s, start, (i - start));
			if (!string[j])
				return (ft_free(string, j));
			j++;
		}
		else
			i++;
	}
	string[j] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**string;

	if (!s)
		return (0);
	string = (char **)malloc(sizeof(char *) * (ft_countstr(s, c) + 1));
	if (!string)
		return (0);
	return (ft_strwordcount(s, c, string));
}
