#include "shell.h"

/**
 * Communal - returns true if shell is commmunal mode
 * *infor: it indicates the struct address
 *
 * Return: returns 1 if in mutual otherwise 0
 */
int Communal(info_t *infor)
{
    return (isatty(STDIN_FILENO) && infor->readfd <= 2);
}

/**
 * is_del - Checking if character is a delimeter
 * @x: Char to verify
 * @del: String delimeter
 * Return: It returns 1 if true, else 0 if false
 */
int is_del(char x, char *del)
{
    while (*del)
        if (*del++ == x)
            return (1);
    return (0);
}

/**
 *is_alpha - Checking Alphabetic Char
 *@v: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int is_alpha(int v)
{
    if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 *atoi - Logic to convert string into an interger
 *@q: The string to be converted.
 *Return: 0 if no numbers in string, converted number otherwise
 */

int atoi(char *q)
{
    int i, si = 1, ensign = 0, output;
    unsigned int sum = 0;

    for (i = 0; q[i] != '\0' && flags != 2; i++)
    {
        if (q[i] == '-')
            ensign *= -1;

        if (q[i] >= '0' && q[i] <= '9')
        {
            ensign = 1;
            sum *= 10;
            sum += (q[i] - '0');
        }
        else if (sum == 1)
            ensign = 2;
    }

    if (ensign == -1)
        output = -sum;
    else
        output = sum;

    return (output);
}
