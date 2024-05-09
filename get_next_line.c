#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    char *buffer;

    line = NULL; 
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (valide_fd(fd, buffer, stash) == -1)
        return (NULL);
    stash = get_stash_from_buffer(fd, stash, buffer);
    if (*stash == 0) // If the first character of stash is NULL or empty string we free the stash and return NULL
    {
        free(stash);
        return (stash = 0);
    }
    line = extract_line(stash, line); // We extract the first line from the stash
    stash = extract_remaining_stash(stash); // We extract the remaining stash
    return (line);
}
// Check if the file descriptor is valid or buffer size is valid or read function is valid
int valide_fd(int fd, char *buffer, char *stash) 
{
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) 
    {
        free(buffer); 
        free(stash); 
        stash = NULL;
        return (-1);
    }
    return (0);
}

char *get_stash_from_buffer(int fd, char *stash, char *buffer)
{
    int nbytes;

    nbytes = 1;
    if (!stash) // If stash is NULL
        stash = ft_strdup(""); // We allocate memory for stash and copy the empty string to it.
    while (nbytes > 0)
    {
        nbytes = read(fd, buffer, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[nbytes] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (stash);
}

char	*extract_line(char *stash, char *line)
{
	int	len;
	int	i;

	len = find_newline_index(stash);
	i = 0;
	if (stash == NULL)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
    while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *extract_remaining_stash(char *stash)
{
    char *remaining_stash;
    int i;
    int len;
    
    i = 0;
    if (stash == NULL)
        return NULL;
    len = find_newline_index(stash);
    remaining_stash = (char *)malloc((ft_strlen(stash) - len + 1) * sizeof(char));
    if (!remaining_stash)
        return NULL;
    while (stash[len + i] != '\0')
	{
		remaining_stash[i] = stash[len + i];
		i++;
	}
    free(stash); // Önceki bellek alanını serbest bırak
    remaining_stash[i] = 0;
    return remaining_stash;
}
int find_newline_index(char *stash)
{
    int i;

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    return (i);
}





//Fonksiyonu her cagirdigimizda surekli buffer size kadar okuma yapacak ve okudugunu buffer'a atacak 
//Fonksiyonu ilk defa cagirdigimizda newline karakteri bulana kadar while dongusu ile buffer size kadar okuma yapacak ve okudugunu stash'a atacak (strjoin ile)
//Buffer da newline gordugunde dönduguden cikacak
//Sonrasinda newline'a kadar olan kismi alip line'a atacak ve line'i return edecek
//Newline'dan sonrasi kismi extract edip stash'a atacak
//Fonksiyon bir daha cagirildiginda yine ayni islemler gercekqlestirilecek ve stash zaten newline'dan sonrasi olacak.
