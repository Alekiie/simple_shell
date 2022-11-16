#include "shell.h"
/**
  * print_list - Prints a linked list
  * @h: Linked list to be printed
  *
  * Return: size of the linked list
  */
size_t print_list(list_e *h)
{
	list_e *c_list = h;
	int count = 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->str == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((c_list->str)[c] != '\0')
				c++;
			write(STDOUT_FILENO, c_list->str, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}
/**
  * add_node_end - Adds a new node at the end of a linked list
  *@head: Pointer to the head of the linked list
  *@str: The string to be added at the end of the linked list
  *
  * Return: Address of the new element or NULL if it fails
  */
list_e *add_end_node(list_e **head, char *str)
{
	char *val;
	int length;
	list_e *newNode, *lastNode;

	newNode = malloc(sizeof(list_e));

	if (newNode == NULL)

		return (NULL);

	val = strdup(str);
	if (str == NULL)
	{
		free(newNode);
		return (NULL);
	}
	for (length = 0; str[length];)
		length++;
	{

		newNode->str = val;
		newNode->next = NULL;
	}
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		lastNode = *head;
		while (lastNode->next != NULL)
			lastNode = lastNode->next;
		lastNode->next = newNode;
	}
	return (*head);
}

/**
  *delete_nodeint_at_index - Deletes node at index
  * @head: Pointer to the head of the linked list
  * @index: The index of the node to be deleted
  *
  * Return: 1 if succeeded and -1 if it fails
  */
int delete_nodeint_at_index(list_e **head, int index)
{
	list_e *temp, *copy = *head;

	int b;

	if (copy == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = (*head)->next;
		free(copy);
		return (1);
	}

	for (b = 0; b < (index - 1); b++)
	{
		if (copy->next == NULL)
		{
			return (-1);
		}
		copy = copy->next;
	}
	temp = copy->next;
	copy->next = temp->next;
	free(temp);
	return (-1);
}

/**
  * free_linked_list - frees a linked list
  * @head: Pointer to a linked list
  *
  * Return: Nothing
  */
void free_linked_list(list_e *head)
{
	list_e *t;

	while (head)
	{
		t = head->next;
		free(head->str);
		free(head);
		head = t;
	}
}
