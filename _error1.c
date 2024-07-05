#include "shell.h"

/**
 * string_to_int - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *         -1 on error
 */
int string_to_int(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @context: the parameter & return context struct
 * @error_str: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *         -1 on error
 */
void print_error(context_t *context, char *error_str)
{
	print_str_to_stderr(context->fname);
	print_str_to_stderr(": ");
	print_num_to_fd(context->line_count, STDERR_FILENO);
	print_str_to_stderr(": ");
	print_str_to_stderr(context->argv[0]);
	print_str_to_stderr(": ");
	print_str_to_stderr(error_str);
}

/**
 * print_num_to_fd - prints a decimal (integer) number (base 10)
 * @num: the number to print
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_num_to_fd(int num, int fd)
{
	int (*putchar_func)(char) = _putchar;
	int i, count = 0;
	unsigned int abs_val, current;

	if (fd == STDERR_FILENO)
		putchar_func = print_char_to_stderr;
	if (num < 0)
	{
		abs_val = -num;
		putchar_func('-');
		count++;
	}
	else
		abs_val = num;
	current = abs_val;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs_val / i)
		{
			putchar_func('0' + current / i);
			count++;
		}
		current %= i;
	}
	putchar_func('0' + current);
	count++;

	return (count);
}

/**
 * convert_num - converter function, a clone of itoa
 * @num: number to convert
 * @base: base to convert to
 * @flags: argument flags
 *
 * Return: string representation of number
 */
char *convert_num(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * strip_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void strip_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

