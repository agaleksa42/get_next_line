/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:16:45 by agaleksa          #+#    #+#             */
/*   Updated: 2026/02/16 19:49:27 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_and_save(int fd, char *stash)
{
    char    *buffer;
    char    *temp;
    int     bytes_read;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    if (!stash)
        stash = ft_strdup("");
    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        if (!stash)
            stash = ft_strdup("");
        temp = stash;
        stash = ft_strjoin(temp, buffer);
        free(temp);
        if (!stash)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    return (stash);
}

static char *extract_line(char *stash)
{
    size_t  i;
    char    *line;

    if (!stash || stash[0] =='\0')
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0, i);
    return (line);
}

static char *update_stash(char *stash)
{
    size_t  i;
    char    *new_stash;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    i++;
    new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
    free(stash);
    return (new_stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_and_save(fd, stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    stash = update_stash(stash);
    return (line);
}