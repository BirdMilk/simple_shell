#include "shell.h"

/**
 * clear_info - Resets all fields in info_t struct to initial values.
 * @info: Pointer to the info_t struct to be cleared.
 */
void clear_info(info_t *info)
{
    info->argument = NULL;
    info->arguments = NULL;
    info->path = NULL;
    info->argument_count = 0;
}

/**
 * set_info - Initializes fields in info_t struct based on command line arguments.
 * @info: Pointer to the info_t struct to be initialized.
 * @av: Argument vector containing command line arguments.
 */
void set_info(info_t *info, char **av)
{
    int i = 0;

    info->program_name = av[0];
    if (info->argument)
    {
        info->arguments = strtow(info->argument, " \t");
        if (!info->arguments)
        {
            info->arguments = malloc(sizeof(char *) * 2);
            if (info->arguments)
            {
                info->arguments[0] = _strdup(info->argument);
                info->arguments[1] = NULL;
            }
        }
        for (i = 0; info->arguments && info->arguments[i]; i++)
            ;
        info->argument_count = i;

        replace_alias(info);
        replace_vars(info);
    }
}

/**
 * free_info - Frees allocated memory in info_t struct.
 * @info: Pointer to the info_t struct to be freed.
 * @all: Boolean flag indicating whether to free all fields.
 */
void free_info(info_t *info, int all)
{
    ffree(info->arguments);
    info->arguments = NULL;
    info->path = NULL;
    if (all)
    {
        if (!info->command_buffer)
            free(info->argument);
        if (info->environment)
            free_list(&(info->environment));
        if (info->history)
            free_list(&(info->history));
        if (info->aliases)
            free_list(&(info->aliases));
        ffree(info->environ);
        info->environ = NULL;
        bfree((void **)&(info->command_buffer));
        if (info->readfd > 2)
            close(info->readfd);
        _putchar(BUF_FLUSH);
    }
}

