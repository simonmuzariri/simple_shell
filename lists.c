#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @h: head node of pointer
 * @s: str field of node
 * @num: node index used by history
 *
 * Return: size
 */
list_t *add_node(list_t **h, const char *s, int num)
{
list_t *new_head;
if (!h)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (s)
{
new_head->s = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *h;
*h = new_head;
return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @h: head note of pointer
 * @s: str field of node
 * @num: node index used by history
 *
 * Return: size
 */
list_t *add_node_end(list_t **h, const char *s, int num)
{
list_t *new_node, *node;

if (!h)
return (NULL);

node = *h;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (s)
{
new_node->s = _strdup(s);
if (!new_node->s)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*h = new_node;
return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
size_t a = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
a++;
}
return (a);
}

/**
 * delete_node_at_index - deletes node at given index
 * @h: head node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **h, unsigned int index)
{
list_t *node, *prev_node;
unsigned int a = 0;
if (!h || !*)
return (0);

if (!index)
{
node = *h;
*h = (*h)->next;
free(node->str);
free(node);
return (1);
}
node = *h;
while (node)
{
if (a == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
a++;
prev_node = node;
node = node->next;
}
#return (0);
}

/**
 * free_list - frees all nodes of a list
 * @h: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **h)
{
list_t *node, *next_node, *head;

if (!h || !*h)
return;
head = *h;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*h = NULL;
}
