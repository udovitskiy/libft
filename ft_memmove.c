/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:31:38 by oxylopho          #+#    #+#             */
/*   Updated: 2020/05/27 23:57:29 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*str1;
	unsigned char			*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str1 > str2)
		while (n--)
			*(str1 + n) = *(str2 + n);
	else
		while (n--)
			*str1++ = *str2++;
	return (dest);
}
