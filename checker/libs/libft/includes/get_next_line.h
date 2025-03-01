/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:48:25 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 18:17:22 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// lib functions
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *s);

// gnl functions
void	gnl_check_free(void **ptr);
char	*get_next_line(int fd);

#endif