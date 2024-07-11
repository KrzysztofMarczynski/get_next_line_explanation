/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarczyn <kmarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:58:14 by kmarczyn          #+#    #+#             */
/*   Updated: 2024/07/11 18:46:19 by kmarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);

# endif