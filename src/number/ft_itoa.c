/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:30:45 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 19:14:01 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_num(int n)
{
	int count;

	count = (n < 0 || n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	numtostr(char *dest, unsigned int n, int i)
{
	if (n >= 10)
	{
		numtostr(dest, n / 10, i - 1);
		dest[i] = n % 10 + '0';
	}
	else
		dest[i] = n + '0';
}

char		*ft_itoa(int n)
{
	unsigned int	temp;
	int				count;
	char			*str;

	count = count_num(n);
	if (!(str = (char*)malloc((count + 1) * sizeof(char))))
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		temp = -n;
	}
	else
		temp = n;
	numtostr(str, temp, count - 1);
	str[count] = '\0';
	return (str);
}
