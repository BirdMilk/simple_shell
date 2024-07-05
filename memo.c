#include "shell.h"

/**
 * safe_free - Frees a pointer and sets the address to NULL
 * @pptr: Address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int safe_free(void **pptr)
{
    if (pptr && *pptr)
    {
        free(*pptr);
        *pptr = NULL;
        return (1);
    }
    return (0);
}

