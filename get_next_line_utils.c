/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_uils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:16:11 by agaleksa          #+#    #+#             */
/*   Updated: 2026/02/16 16:18:25 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
	size_t	i;

    if (!s)
        return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  i;
    char    a;

    if (!s)
        return (NULL);
    i = 0;
    a = (char)c;
    while (s[i])
    {
        if (s[i] == a)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] == a)
        return ((char *)&s[i]);
    return (NULL);
}

char *ft_strdup(const char *s)
{
    size_t  i;
    char    *ptr;
    size_t  len;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s[i])
    {
        ptr[i] = s[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    size_t  s_len;
    char    *ptr;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  s1_len;
    size_t  s2_len;
    size_t  i;
    char    *ptr;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    ptr = malloc((s1_len + s2_len + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        ptr[s1_len + i] = s2[i];
        i++;
    }
    ptr[s1_len + i] = '\0';
    return (ptr);
}
