/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:44:02 by jordgarc          #+#    #+#             */
/*   Updated: 2024/03/12 18:10:36 by jordgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(str))
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < ft_strlen(str) && i < len && str[start])
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}
