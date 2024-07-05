#include "shell.h"

/**
 * list_len - Determines the length of a linked list.
 * @head: Pointer to the first node.
 *
 * Return: Length of the list.
 */
size_t list_len(const list_t *head)
{
    size_t length = 0;

    while (head)
    {
        head = head->next;
        length++;
    }
    return (length);
}

/**
 * list_to_strings - Converts a linked list to an array of strings.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings or NULL if it fails.
 */
char **list_to_strings(list_t *head)
{
    list_t *current = head;
    size_t length = list_len(head), i;
    char **strs;
    char *str;

    if (!head || !length)
        return (NULL);

    strs = malloc(sizeof(char *) * (length + 1));
    if (!strs)
        return (NULL);

    for (i = 0; current; current = current->next, i++)
    {
        str = malloc(_strlen(current->str) + 1);
        if (!str)
        {
            for (size_t j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }
        strs[i] = _strcpy(str, current->str);
    }
    strs[i] = NULL;

    return (strs);
}

/**
 * print_list - Prints all elements of a list_t linked list.
 * @head: Pointer to the first node.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        _puts(convert_number(head->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        count++;
    }
    return (count);
}

/**
 * node_starts_with - Finds a node whose string starts with a given prefix.
 * @head: Pointer to the first node.
 * @prefix: String prefix to match.
 * @c: Character that must follow the prefix.
 *
 * Return: Pointer to the matching node or NULL if no match is found.
 */
list_t *node_starts_with(list_t *head, char *prefix, char c)
{
    char *p = NULL;

    while (head)
    {
        p = starts_with(head->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return (head);
        head = head->next;
    }
    return (NULL);
}

/**
 * get_node_index - Gets the index of a node in a linked list.
 * @head: Pointer to the first node.
 * @node: Pointer to the node to find.
 *
 * Return: Index of the node or -1 if not found.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    size_t index = 0;

    while (head)
    {
        if (head == node)
            return (index);
        head = head->next;
        index++;
    }
    return (-1);
}

