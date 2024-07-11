/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarczyn <kmarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:28 by kmarczyn          #+#    #+#             */
/*   Updated: 2024/07/11 18:45:11 by kmarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char *)&s[i]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	len = ft_strlen(src);
	src_len = 0;
	if (size != 0)
	{
		while (src[src_len] != '\0' && src_len < (size - 1))
		{
			dst[src_len] = src[src_len];
			src_len++;
		}
		dst[src_len] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	while ((dst_len + src_len + 1) < size && src[src_len])
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len != size)
		dst[dst_len + src_len] = '\0';
	return (dst_len + ft_strlen(src));
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char *strjoined;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	strjoined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoined)
		return (NULL);
	ft_strlcpy(strjoined, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(strjoined, (char *)s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	free(s1);
	return (strjoined);
}