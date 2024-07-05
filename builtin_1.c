#include "shell.h"

/**
 * show_history - Outputs the command history list, one per line, with line numbers starting at 0.
 * @context: Structure containing arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int show_history(context_t *context)
{
    display_list(context->history);
    return (0);
}

/**
 * remove_alias - Removes an alias from the list
 * @context: parameter structure
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int remove_alias(context_t *context, char *alias_str)
{
    char *delimiter_pos, temp_char;
    int result;

    delimiter_pos = find_char(alias_str, '=');
    if (!delimiter_pos)
        return (1);
    temp_char = *delimiter_pos;
    *delimiter_pos = 0;
    result = delete_node_by_index(&(context->alias),
                                  find_node_index(context->alias, starts_with_node(context->alias, alias_str, -1)));
    *delimiter_pos = temp_char;
    return (result);
}

/**
 * add_alias - Adds or updates an alias in the list
 * @context: parameter structure
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int add_alias(context_t *context, char *alias_str)
{
    char *delimiter_pos;

    delimiter_pos = find_char(alias_str, '=');
    if (!delimiter_pos)
        return (1);
    if (!*++delimiter_pos)
        return (remove_alias(context, alias_str));

    remove_alias(context, alias_str);
    return (append_node(&(context->alias), alias_str, 0) == NULL);
}

/**
 * display_alias - Outputs an alias string
 * @alias_node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int display_alias(list_t *alias_node)
{
    char *delimiter_pos = NULL, *start = NULL;

    if (alias_node)
    {
        delimiter_pos = find_char(alias_node->str, '=');
        for (start = alias_node->str; start <= delimiter_pos; start++)
            output_char(*start);
        output_char('\'');
        output_str(delimiter_pos + 1);
        output_str("'\n");
        return (0);
    }
    return (1);
}

/**
 * manage_alias - Imitates the alias command (man alias)
 * @context: Structure containing arguments. Ensures consistent function signature.
 * Return: Always 0
 */
int manage_alias(context_t *context)
{
    int idx = 0;
    char *delimiter_pos = NULL;
    list_t *alias_node = NULL;

    if (context->argc == 1)
    {
        alias_node = context->alias;
        while (alias_node)
        {
            display_alias(alias_node);
            alias_node = alias_node->next;
        }
        return (0);
    }
    for (idx = 1; context->argv[idx]; idx++)
    {
        delimiter_pos = find_char(context->argv[idx], '=');
        if (delimiter_pos)
            add_alias(context, context->argv[idx]);
        else
            display_alias(starts_with_node(context->alias, context->argv[idx], '='));
    }

    return (0);
}

