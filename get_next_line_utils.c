#include "get_next_line.h"


int    ft_strlen(const char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strcpy(char *dest, const char *src)
{
    int    i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *ft_strdup(const char *s)
{
    int        i;
    char    *copy;

    i = 0;
    while (s[i])
        i++;
    copy = (char *) malloc(sizeof(char) * (i + 1));
    if (!copy)
        return (0);
    ft_strcpy(copy, s);
    return (copy);
}

char    *ft_strcat(char *dest, const char *src)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    int        totallen;
    char    *output;

    totallen = ft_strlen(s1) + ft_strlen(s2) + 1;
    output = (char *)malloc(totallen);
    if (output == NULL)
        return (NULL);
    output[0] = '\0';
    ft_strcat(output, s1);
    ft_strcat(output, s2);
    return (output);
}

char    *ft_strchr(const char *s, int c)
{
    const unsigned char    *str;
    unsigned char        b;

    b = (unsigned char)c;
    str = (const unsigned char *)s;
    while (*str != '\0')
    {
        if (*str == b)
        {
            return ((char *)str);
        }
        str++;
    }
    if (b == '\0')
    {
        return ((char *)str);
    }
    return (0);
}
