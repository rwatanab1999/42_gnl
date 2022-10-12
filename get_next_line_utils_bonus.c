/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:41:01 by rwatanab          #+#    #+#             */
/*   Updated: 2022/10/12 17:47:58 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gnl_strlen(src));
}

size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (gnl_strlen(src));
	dst_len = gnl_strlen(dst);
	src_len = gnl_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] != '\0' && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	len = s1_len + s2_len + 1;
	str = (char *) malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	gnl_strlcpy(str, s1, s1_len + 1);
	gnl_strlcat(str, s2, len);
	return (str);
}

char	*gnl_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (gnl_strlen(s) < len)
		str = (char *)malloc((gnl_strlen(s) + 1) * sizeof(*s));
	else
		str = (char *)malloc((len + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
