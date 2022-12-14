/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:11:59 by rwatanab          #+#    #+#             */
/*   Updated: 2022/10/13 01:08:41 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_substr(char const *s, size_t start, size_t len);

#endif