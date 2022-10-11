/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:32 by rwatanab          #+#    #+#             */
/*   Updated: 2022/10/12 06:11:35 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	line = "";
// 	fd = open("file.txt", O_RDONLY);
// 	printf("_________________test start_________________\n");
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("> %s", line);
// 		free(line);
// 	}
// 	printf("\n_________________test end___________________\n");
// 	system("leaks a.out");
// 	return (0);
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*read_func(int fd, char *save)
{
	int		read_ret;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	char	*str;

	read_ret = read(fd, buf, BUFFER_SIZE);
	if ((read_ret == 0 && save == NULL) || read_ret == -1)
		return (NULL);
	str = save;
	while (read_ret > 0)
	{
		buf[read_ret] = '\0';
		if (!str)
			str = ft_strjoin((tmp = ""), buf);
		else
		{
			str = ft_strjoin((tmp = str), buf);
			free(tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
		read_ret = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*save = NULL;
	char			*line;
	size_t			s_len;
	size_t			n_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(save, '\n'))
		str = save;
	else
		str = read_func(fd, save);
	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	n_len = n_check(str);
	line = ft_substr(str, 0, n_len + 1);
	if (n_len != s_len && str[1] != '\0')
		save = ft_substr(str, n_len + 1, s_len - (n_len + 1));
	else
		save = NULL;
	free_func(&str);
	if (!ft_strchr(line, '\n') && !ft_strlen(line))
		return (free_func(&line));
	return (line);
}
