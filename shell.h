#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

void _prompt(void);
void print_stdout(const char *user_input);
void get_command(char *command, size_t size);
void exit_shell(void);


#endif /* SHELL_H */
