/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:42:42 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/17 06:41:49 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_stop(char **str)
{
	int a;

	a = 0;
	while (str[a])
		free(str[a++]);
	free(str);
	return (NULL);
}

static int	ft_word(char const *str, char c)
{
	int count;
	int a;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] != c)
		{
			count++;
			while (str[a] != c && str[a])
				a++;
		}
		else
			a++;
	}
	return (count);
}

static char	*ft_cast(char const *s, char c)
{
	int		a;
	char	*word;

	a = 0;
	if (!(word = ft_memalloc((ft_count_letter(s, c) + 1))))
		return (NULL);
	while (s[a] != c && s[a])
	{
		word[a] = s[a];
		a++;
	}
	word[a] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		a;
	char	**new;

	a = 0;
	if (!s || !(new = ft_memalloc((ft_word(s, c) + 1))))
		return (NULL);
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		if (s[a] != c && s[a])
		{
			if (!(ft_cast(s + a, c)))
				return (ft_stop(new));
			*new = ft_cast(s + a, c);
			new++;
			while (s[a] != c && s[a])
				a++;
		}
	}
	*new = NULL;
	return (new - ft_word(s, c));
}
