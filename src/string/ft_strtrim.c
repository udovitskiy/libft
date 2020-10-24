/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:30:45 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 19:14:01 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	is_trim(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && is_trim(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && is_trim(*(s1 + len - 1), set))
		len--;
	if (!(str = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
