#include "shell.h"

/**
 * add_node - Adds a node to the start of the list.
 * @head: Address of pointer to the head node.
 * @str: String field of the node.
 * @num: Node index used by history.
 *
 * Return: Pointer to the new head of the list.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return (NULL);

    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);

    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = num;

    if (str)
    {
        new_head->str = _strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }

    new_head->next = *head;
    *head = new_head;

    return (new_head);
}

/**
 * add_node_end - Adds a node to the end of the list.
 * @head: Address of pointer to the head node.
 * @str: String field of the node.
 * @num: Node index used by history.
 *
 * Return: Pointer to the new node added at the end of the list.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *temp_node;

    if (!head)
        return (NULL);

    temp_node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }

    if (temp_node)
    {
        while (temp_node->next)
            temp_node = temp_node->next;
        temp_node->next = new_node;
    }
    else
        *head = new_node;

    return (new_node);
}

/**
 * print_list_str - Prints only the string element of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list_str(const list_t *h)
{
    size_t count = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        count++;
    }

    return (count);
}

/**
 * delete_node_at_index - Deletes a node at a given index.
 * @head: Address of pointer to the first node.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, 0 on failure.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    list_t *current_node, *previous_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    if (index == 0)
    {
        current_node = *head;
        *head = (*head)->next;
        free(current_node->str);
        free(current_node);
        return (1);
    }

    current_node = *head;

    while (current_node)
    {
        if (i == index)
        {
            previous_node->next = current_node->next;
            free(current_node->str);
            free(current_node);
            return (1);
        }
        i++;
        previous_node = current_node;
        current_node = current_node->next;
    }

    return (0);
}

/**
 * free_list - Frees all nodes of a list.
 * @head_ptr: Address of pointer to the head node.
 *
 * Return: Void.
 */
void free_list(list_t **head_ptr)
{
    list_t *current_node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;

    head = *head_ptr;
    current_node = head;

    while (current_node)
    {
        next_node = current_node->next;
        free(current_node->str);
        free(current_node);
        current_node = next_node;
    }

    *head_ptr = NULL;
}

