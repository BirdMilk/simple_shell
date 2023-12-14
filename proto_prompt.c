#include "shell.h"

/**
 * _prompt - Display a simple shell prompt.
 *
 * Description:
 * This function prints the shell prompt,
 * which consists of a
 * dollar sign ('$')
 * followed by a space. The output is
 * flushed to ensure it is immediately visible
 * in the terminal. It is typically called
 * before waiting for user input.
 */

void _prompt(void)
{
	print_stdout("$ ");
	fflush(stdout);
}
