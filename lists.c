#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head1;

	if (!head)
		return (NULL);
	new_head1 = malloc(sizeof(list_t));
	if (!new_head1)
		return (NULL);
	_memset((void *)new_head1, 0, sizeof(list_t));
	new_head1->num = num;
	if (str)
	{
		new_head1->str = _strdup(str);
		if (!new_head1->str)
		{
			free(new_head1);
			return (NULL);
		}
	}
	new_head1->next = *head;
	*head = new_head1;
	return (new_head1);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node1, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node1 = malloc(sizeof(list_t));
	if (!new_node1)
		return (NULL);
	_memset((void *)new_node1, 0, sizeof(list_t));
	new_node1->num = num;
	if (str)
	{
		new_node1->str = _strdup(str);
		if (!new_node1->str)
		{
			free(new_node1);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node1;
	}
	else
		*head = new_node1;
	return (new_node1);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node1, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node1 = *head;
		*head = (*head)->next;
		free(node1->str);
		free(node1);
		return (1);
	}
	node1 = *head;
	while (node1)
	{
		if (i == index)
		{
			prev_node->next = node1->next;
			free(node1->str);
			free(node1);
			return (1);
		}
		i++;
		prev_node = node1;
		node1 = node1->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
