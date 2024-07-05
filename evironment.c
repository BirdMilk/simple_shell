#include "shell.h"

/**
 * display_env - prints the current environment
 * @context: Structure containing potential arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int display_env(context_t *context)
{
    print_list_str(context->env);
    return (0);
}

/**
 * get_env_var - gets the value of an environment variable
 * @context: Structure containing potential arguments. Ensures consistent function signature.
 * @name: environment variable name
 *
 * Return: the value
 */
char *get_env_var(context_t *context, const char *name)
{
    list_t *node = context->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}

/**
 * set_env_var - Initialize a new environment variable, or modify an existing one
 * @context: Structure containing potential arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int set_env_var(context_t *context)
{
    if (context->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return (1);
    }
    if (_setenv(context, context->argv[1], context->argv[2]))
        return (0);
    return (1);
}

/**
 * unset_env_var - Remove an environment variable
 * @context: Structure containing potential arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int unset_env_var(context_t *context)
{
    int i;

    if (context->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return (1);
    }
    for (i = 1; i <= context->argc; i++)
        _unsetenv(context, context->argv[i]);

    return (0);
}

/**
 * init_env_list - Populates the environment linked list
 * @context: Structure containing potential arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int init_env_list(context_t *context)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    context->env = node;
    return (0);
}

