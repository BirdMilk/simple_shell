#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 0
#define EXIT FILENAME_MAX 200
#define WAIT_CHILD _WAIT_CHILD
#define _GNU_SOURCE

//Promt fuction
int prompt(const char *__restrict__ _Format, ...);

//wait fuction
pid_t wait(int *stat);
pid_t WAIT_CHILD;

//getline
ssize_t getline(char **restrict line, size_t *restrict x, FILE *restrict stream, int argc, char *argv[]);

//execve
int execve(const char *file_name, char *const argv[], char *const envp[]);

#endif /* SHELL_H */
