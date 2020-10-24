/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_empty_str_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:38:17 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 19:38:49 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*new_empty_str_err(int *result)
{
	char	*line;

	if (!(line = (char *)malloc(sizeof(char))))
	{
		*result = -1;
		return (NULL);
	}
	line[0] = '\0';
	return (line);
}