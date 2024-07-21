#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _linked_list
{
    Node *begin;
} LinkedList;


LinkedList *LinkedList_create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if(!list)
        return (NULL);
    list->begin = NULL;
    
    return (list);
}

Node *Node_create(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(!node)
        return (NULL);
    
    node->value = value;
    node->next = NULL;
    
    return (node);
}

void LinkedList_add_first(LinkedList *list, int value)
{
    if(list->begin == NULL)
    {
        Node *newNode = Node_create(value);
        list->begin = newNode;
    }else
    {
        Node *newNode = Node_create(value);
        newNode->next = list->begin;
        list->begin = newNode;
    }
}

void LinkedList_print(LinkedList *list)
{
    Node *node = list->begin;

    while(node != NULL)
    {
        printf("Endereco = %p - Valor = %d\n", &node->value, node->value);    
        node = node->next;
    }
}

void LinkedList_add_last(LinkedList *list, int value)
{
    Node *newNode = Node_create(value);
    if(list->begin == NULL)
    {
        list->begin = newNode;
    }else
    {
        Node *node = list->begin;
        while(node->next != NULL)
            node = node->next;
        node->next = newNode;
    }
}

int main(void)
{
    LinkedList *list = LinkedList_create();

    LinkedList_add_first(list, 10);
    LinkedList_add_first(list, 11);
    LinkedList_add_first(list, 12);
    LinkedList_add_last(list, 5);
    LinkedList_add_last(list, 6);
    LinkedList_add_first(list, 13);

    LinkedList_print(list);
}