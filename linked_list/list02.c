#include <stdio.h>
#include <stdlib.h>

typedef struct	_node
{
	int	value;
	struct _node	*next;
}	Node;

typedef struct	_linked_list
{
	Node	*begin;
}	Linked_List;

Linked_List	*Create_List(void)
{
	Linked_List *list = (Linked_List *)malloc(sizeof(Linked_List));
	if(!list)
		return (NULL);
	list->begin = NULL;
	return (list);
}

Node	*Create_Node(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if(!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	*Linked_List_Add_First(Linked_List *list, int value)
{
	Node *node = Create_Node(value);
	if(!node)
		return (NULL);
	if(list->begin == NULL)
		list->begin = node;
	else
	{
		node->next = list->begin;
		list->begin = node;
	}
}

void	*Linked_List_Add_Last(Linked_List *list ,int value)
{
	Node *current = list->begin;
	Node *node = Create_Node(value);

	if(current == NULL)
		list->begin = node;
	else
	{		
		while(current->next != NULL)
			current = current->next;
		current->next = node;
	}	

}

void	*Print_List(Linked_List *list)
{
	Node *current;

	current = list->begin;
	if(current == NULL)
		return (NULL);
	while(current != NULL)
	{
		printf("Valor = %d\n", current->value);
		current = current->next;
	}
}

void	Linked_List_Destroy(Linked_List *list)
{
	if(list->begin == NULL)
		return;
	Node *current = list->begin;
	while(current != NULL)
	{
		Node *next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

void	Linked_List_Remove_First(Linked_List *list)
{
	Node	*current;
	
	if(list->begin == NULL)
		return;
	current = list->begin;
	list->begin = list->begin->next;
	free(current);
}

void Linked_List_Remove_Last(Linked_List *list)
{
	Node	*current;
	Node	*node_to_remove;
	if(list->begin == NULL)
		return;
	current = list->begin;
	if(current->next == NULL)
	{
		free(current);
		list->begin = NULL;
	}
	else
	{

			while(current->next->next != NULL)
				current = current->next;
			free(current->next);
			current->next = NULL;
		}
	}
	int	main(void)
	{
		Linked_List *list = Create_List();
	Linked_List_Add_First(list, 2);
	Linked_List_Add_First(list, 3);
	Linked_List_Add_First(list, 0);
	Linked_List_Add_Last(list, -1);
	Linked_List_Add_Last(list, 10);
	Print_List(list);
	printf("\n\n\n");
	Linked_List_Remove_First(list);
	Linked_List_Remove_Last(list);
	Print_List(list);
	Linked_List_Destroy(list);
	return (0);
}
