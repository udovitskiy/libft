/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:30:45 by oxylopho          #+#    #+#             */
/*   Updated: 2020/05/30 17:18:49 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i + 1] && s[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}

static int	len_str(char const *str, char c)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*del_array(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	**fill_array(char const *s, char c, char **split, int count)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	str = (char *)s;
	while (j < count)
	{
		i = len_str(str, c);
		if (i > 0)
		{
			if (!(split[j++] = ft_substr(str, 0, i)))
				return (del_array(split));
		}
		i++;
		str += i;
	}
	split[j] = NULL;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	int		count;
	char	**arr_str;

	count = count_str(s, c);
	if (!s)
		return (NULL);
	if (!(arr_str = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	return (fill_array(s, c, arr_str, count));
}
