#include "shell.h"

/**
 * str_copy - copies a string
 * @dest: the destination buffer
 * @src: the source string
 *
 * Return: pointer to the destination buffer
 */
char *str_copy(char *dest, char *src)
{
    int index = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[index])
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = 0;
    return (dest);
}

/**
 * str_duplicate - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *str_duplicate(const char *str)
{
    int length = 0;
    char *dup_str;

    if (str == NULL)
        return (NULL);
    while (*str++)
        length++;
    dup_str = malloc(sizeof(char) * (length + 1));
    if (!dup_str)
        return (NULL);
    for (length++; length--;)
        dup_str[length] = *--str;
    return (dup_str);
}

/**
 * print_string - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void print_string(char *str)
{
    int index = 0;

    if (!str)
        return;
    while (str[index] != '\0')
    {
        print_char(str[index]);
        index++;
    }
}

/**
 * print_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(char c)
{
    static int index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
    {
        write(1, buffer, index);
        index = 0;
    }
    if (c != BUF_FLUSH)
        buffer[index++] = c;
    return (1);
}

