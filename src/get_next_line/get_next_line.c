/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:58:28 by oxylopho          #+#    #+#             */
/*   Updated: 2020/10/24 20:37:07 by oxylopho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin_err(char *s1, char *s2, int *result)
{
	char	*str;
	int		len;
	int		i;
	char	*temp;

	i = 0;
	temp = s1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char *)malloc(len * sizeof(char))))
	{
		*result = -1;
		return (NULL);
	}
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(temp);
	return (str);
}

char	*ft_strdup_err(char *s, int *result)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		*result = -1;
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	init_remainds(char **p_str, char *buf, char **remainds, int *result)
{
	char	*temp;

	buf[*result] = '\0';
	if ((*p_str = ft_strchr(buf, '\n')))
	{
		**p_str = '\0';
		temp = *remainds;
		(*p_str)++;
		*remainds = ft_strdup_err(*p_str, result);
		free(temp);
	}
}

char	*init_line(char *remainds, char **line, int *result)
{
	char	*p_str;

	*result = 1;
	p_str = NULL;
	if (!line)
		*result = -1;
	if (remainds)
	{
		if ((p_str = ft_strchr(remainds, '\n')))
		{
			*p_str = '\0';
			*line = ft_strdup_err(remainds, result);
			ft_strcpy(remainds, ++p_str);
		}
		else
		{
			*line = ft_strdup_err(remainds, result);
			ft_strclr(remainds);
		}
	}
	else if (*result != -1)
		*line = new_empty_str_err(result);
	return (p_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainds;
	char		*buf;
	int			result;
	char		*p_str;
	int			len;

	if ((read(fd, NULL, 0) == -1) || (BUFFER_SIZE < 1))
		return (-1);
	p_str = init_line(remainds, line, &result);
	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (!p_str && result != -1 && (result = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		init_remainds(&p_str, buf, &remainds, &result);
		*line = ft_strjoin_err(*line, buf, &result);
	}
	free(buf);
	if (result == -1)
		return (-1);
	if (!(len = ft_strlen(remainds)) && !result)
	{
		free(remainds);
		remainds = NULL;
	}
	return (len || result);
}
