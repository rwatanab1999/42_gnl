/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:09:17 by rwatanab          #+#    #+#             */
/*   Updated: 2022/10/13 01:10:31 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int		fd1, fd2, fd3;
// 	char	*line;

// 	line = "";
// 	fd1 = open("./file1.txt", O_RDONLY);
// 	fd2 = open("./file2.txt", O_RDONLY);
// 	fd3 = open("./file3.txt", O_RDONLY);
// 	printf("_________________test start_________________\n");
// 	while (1)
// 	{
// 		line = get_next_line(fd1);
// 		printf("> %s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("> %s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("> %s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 	}
// 	printf("\n_________________test end___________________\n");
// 	free(line);
// 	system("leaks a.out");
// 	return (0);
// }

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	n_check(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*free_func(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*read_func(int fd, char **save)
{
	int		read_ret;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	read_ret = read(fd, buf, BUFFER_SIZE);
	if ((read_ret == 0 && *save == NULL) || read_ret == -1)
		return (NULL);
	while (read_ret > 0)
	{
		buf[read_ret] = '\0';
		if (!(*save))
			*save = gnl_strjoin((tmp = ""), buf);
		else
		{
			*save = gnl_strjoin((tmp = *save), buf);
			free_func(&tmp);
		}
		if (gnl_strchr(buf, '\n'))
			break ;
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (free_func(&(*save)));
	}
	return (*save);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*save[MAX_FILE] = {NULL};
	char			*line;
	size_t			s_len;
	size_t			n_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_strchr(save[fd], '\n'))
		str = save[fd];
	else
		str = read_func(fd, &(save[fd]));
	if (!str)
		return (NULL);
	s_len = gnl_strlen(str);
	n_len = n_check(str);
	line = gnl_substr(str, 0, n_len + 1);
	if (n_len != s_len && str[1] != '\0')
		save[fd] = gnl_substr(str, n_len + 1, s_len - (n_len + 1));
	else
		save[fd] = NULL;
	free_func(&str);
	if (!gnl_strchr(line, '\n') && !gnl_strlen(line))
		return (free_func(&line));
	return (line);
}
