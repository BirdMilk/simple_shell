#include "shell.h"


/**
 * get_command - Get user input for a shell command.
 * @command: Buffer to store the user input.
 * @size: Size of the buffer.
 *
 * Description:
 * This function reads a line of input
 * from the standard input (stdin)
 * using fgets. If the end-of-file (EOF)
 * is encountered, the program exits
 * with success. If an error occurs during
 * input, the program exits with
 * failure. The newline character,
 * if present, is replaced with a null
 * terminator in the command buffer.
 */

void get_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_stdout("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			print_stdout("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
