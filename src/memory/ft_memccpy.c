/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:31:26 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 19:14:01 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	while (n--)
	{
		if (*str2 == (unsigned char)c)
		{
			*str1++ = *str2++;
			return (str1);
		}
		*str1++ = *str2++;
	}
	return (NULL);
}
