#include "shell.h"

/**
 * print_stdout - Print a string to the standard output.
 * @user_input: The string to be printed.
 *
 * Description:
 * This function writes the specified string to the standard output (stdout)
 * using the write system call. It takes the string as input and determines
 * its length using strlen before printing it to the console.
 *
 * @user_input: The string to be printed to the standard output.
 */

void print_stdout(const char *user_input)
{
	write(STDOUT_FILENO, user_input, strlen(user_input));
}
