#include "shell.h"

/**
 * fill_memory - fills memory with a constant byte
 * @mem_area: pointer to the memory area
 * @byte: the byte to fill the memory area with
 * @n: the number of bytes to be filled
 *
 * Return: pointer to the memory area
 */
char *fill_memory(char *mem_area, char byte, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        mem_area[i] = byte;
    return (mem_area);
}

/**
 * free_string_array - frees a dynamically allocated array of strings
 * @str_array: array of strings
 */
void free_string_array(char **str_array)
{
    char **temp = str_array;

    if (!str_array)
        return;
    while (*str_array)
        free(*str_array++);
    free(temp);
}

/**
 * realloc_memory - reallocates a block of memory
 * @ptr: pointer to the previously allocated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the newly allocated block, or NULL on failure
 */
void *realloc_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);

    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        new_ptr[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (new_ptr);
}

