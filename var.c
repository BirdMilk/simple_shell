#include "shell.h"

/**
 * is_chain_delim - test if current char in buffer is a chain delimiter
 * @info: the parameter struct
 * @buf: the char buffer
 * @pos: address of current position in buf
 *
 * Return: 1 if chain delimiter, 0 otherwise
 */
int is_chain_delim(info_t *info, char *buf, size_t *pos)
{
    size_t current_pos = *pos;

    if (buf[current_pos] == '|' && buf[current_pos + 1] == '|')
    {
        buf[current_pos] = 0;
        current_pos++;
        info->cmd_buf_type = CMD_OR;
    }
    else if (buf[current_pos] == '&' && buf[current_pos + 1] == '&')
    {
        buf[current_pos] = 0;
        current_pos++;
        info->cmd_buf_type = CMD_AND;
    }
    else if (buf[current_pos] == ';') /* found end of this command */
    {
        buf[current_pos] = 0; /* replace semicolon with null */
        info->cmd_buf_type = CMD_CHAIN;
    }
    else
        return (0);
    *pos = current_pos;
    return (1);
}

/**
 * check_chain_continuation - checks if we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @pos: address of current position in buf
 * @start_pos: starting position in buf
 * @buf_len: length of buf
 *
 * Return: Void
 */
void check_chain_continuation(info_t *info, char *buf, size_t *pos, size_t start_pos, size_t buf_len)
{
    size_t current_pos = *pos;

    if (info->cmd_buf_type == CMD_AND)
    {
        if (info->status)
        {
            buf[start_pos] = 0;
            current_pos = buf_len;
        }
    }
    if (info->cmd_buf_type == CMD_OR)
    {
        if (!info->status)
        {
            buf[start_pos] = 0;
            current_pos = buf_len;
        }
    }

    *pos = current_pos;
}

/**
 * replace_aliases - replaces aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_aliases(info_t *info)
{
    int i;
    list_t *node;
    char *alias_value;

    for (i = 0; i < 10; i++)
    {
        node = node_starts_with(info->alias, info->argv[0], '=');
        if (!node)
            return (0);
        free(info->argv[0]);
        alias_value = _strchr(node->str, '=');
        if (!alias_value)
            return (0);
        alias_value = _strdup(alias_value + 1);
        if (!alias_value)
            return (0);
        info->argv[0] = alias_value;
    }
    return (1);
}

/**
 * replace_variables - replaces variables in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_variables(info_t *info)
{
    int i = 0;
    list_t *node;

    for (i = 0; info->argv[i]; i++)
    {
        if (info->argv[i][0] != '$' || !info->argv[i][1])
            continue;

        if (!_strcmp(info->argv[i], "$?"))
        {
            replace_string(&(info->argv[i]),
                           _strdup(convert_number(info->status, 10, 0)));
            continue;
        }
        if (!_strcmp(info->argv[i], "$$"))
        {
            replace_string(&(info->argv[i]),
                           _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = node_starts_with(info->env, &info->argv[i][1], '=');
        if (node)
        {
            replace_string(&(info->argv[i]),
                           _strdup(_strchr(node->str, '=') + 1));
            continue;
        }
        replace_string(&info->argv[i], _strdup(""));
    }
    return (0);
}

/**
 * replace_string - replaces a string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
    return (1);
}

