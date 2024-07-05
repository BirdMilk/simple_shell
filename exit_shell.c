#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to copy to
 * @src: the source string
 * @n: the maximum number of characters to copy
 *
 * Return: pointer to the destination string `dest`
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *dest_ptr = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (dest_ptr);
}

/**
 * _strncat - concatenates two strings
 * @dest: the destination string
 * @src: the source string to append
 * @n: the maximum number of bytes from `src` to append
 *
 * Return: pointer to the destination string `dest`
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *dest_ptr = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (dest_ptr);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to find
 *
 * Return: pointer to the first occurrence of `c` in `s`, or NULL if not found
 */
char *_strchr(char *s, char c)
{
    do
    {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}

