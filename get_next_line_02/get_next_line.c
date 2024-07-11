/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarczyn <kmarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:45:18 by kmarczyn          #+#    #+#             */
/*   Updated: 2024/07/11 21:21:15 by kmarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// funkcja ta służy do przenoszenia naszego pliku który chcemy odczytać do buffera aby móc dzięki temu operować na nim

// w pierwszej kolejności alokujemy pamięć w tymczasowej zmiennej która przechowuje nasz teskt plus termiantor

// nastepnie sprwdza czy nasz temp wg istnieje

// nasza zmienna bts odczytuje plik (fd) w raz z rozmiarem naszego buffera oraz wpisujemy nasz temp czyli nasza zaalokowaną pamięć

// jeśli funkcja read wrzuci błąd to zwalnia w tym momencie pamięc z tempa i buffera

// jeśli jednak tak się nie stanie to przypisuje terminator na końcu naszego stringa a następnie scala go do buffera aby był to kompletny string

// na samym końcu zwalnia wszystko co jest w naszej tymczasowej zmiennej a w naszym bufferze jest zaalokowany string

static char	*ft_file_to_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bts;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	bts = 1;
	while (bts > 0 && !ft_strchr(buffer, '\n'))
	{
		bts = read(fd, temp, BUFFER_SIZE);
		if (bts == -1)
		{
			if (buffer)
				free(buffer);
			free(temp);
			return (0);
		}
		temp[bts] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

// ta funkcja zajmuje się allokowanie naszego buffera do stałej zmiennej string

// w pierwszej kolejności nasza funckaj sprawdza czy nasz buffer wg istnieje

// kiedy buffer istnieje bądz na mijescu jest nowa linijka to przechodzi na następne miejsce

// jeśli na naszym mijescu jest nowa linijka to również przechodzi na nastepne miejsce

// w kolejnej linijce alokoujemy miejsce w na naszego stringa + 1 na termianator

// jeśli nasz string nie istnieje to zwracamy błąd

// na ostatnim mniejscu w maszym stringu przypisujemy terminator

// w ostatnije fazie przepisujemy to co mamy w bufforze do stringa iterując to od tyłu następnie zwracamy to wszystko

static char	*ft_buffer_to_line(char *buffer)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
		i++;
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (0);
	string[i] = '\0';
	while (--i + 1)
		string[i] = buffer[i];
	return (string);
}

// ta funkcja służy odświeżania bufferu aby nasz program działał na każdej wielkości buffera

// kiedy nasz buffer jest pusty wywala błąd

// kiedy na naszym miejscu w bufferze nie jest nowa linijka przechodzimy na następne miejsce

// nastepnie jeśli jest to nowa linijka przeskakujemy na nastepne miejsce

// potem zwalniamy buffera jeśli tak owy nie istnieje

// alokujemy długość naszego buffera minus naszą mijesca na nowe linijki plus 1 dla termiantora

// kiedy buffer istnieje przypisujemy buffer do stringa a na końcu wpisujemy wspomniany terminator

// zwalniamy buffer i zwracamy stringa

char	*ft_loop_buffer(char *buffer)
{
	char	*string;
	size_t	bi;
	size_t	si;

	bi = 0;
	si = 0;
	if (!buffer)
		return (0);
	while (buffer[bi] && buffer[bi] != '\n')
		bi++;
	if (buffer[bi] == '\n')
		bi++;
	if (!buffer[bi])
	{
		free(buffer);
		return (0);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(buffer), -bi + 1));
	if (!string)
		return (0);
	while (buffer[bi])
		string[si++] = buffer[bi++];
	string[si] = '\0';
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = ft_file_to_buffer(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_buffer_to_line(buffer);
	buffer = ft_loop_buffer(buffer);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file.\n");
// 		return (1);
// 	}
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 	}
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			return (0);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }