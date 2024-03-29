/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:30:45 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 19:14:01 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;
	t_list *temp;

	if (lst && *lst && del)
	{
		list = *lst;
		while (list)
		{
			temp = list;
			list = list->next;
			ft_lstdelone(temp, del);
		}
		*lst = NULL;
	}
}
