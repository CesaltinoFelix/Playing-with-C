#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _linked_list
{
    Node *begin;
    Node *end;
} LinkedList;


bool is_empty(LinkedList *list)
{
    return (list->begin == NULL && list->end == NULL);
}

LinkedList *LinkedList_create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if(!list)
        return (NULL);
    list->begin = NULL;
    list->end = NULL;
    
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
    Node *newNode = Node_create(value);
    if(is_empty(list))
    {
        list->begin = newNode;
        list->end = newNode;
    }else
    { 
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
    if(is_empty(list))
    {
        list->begin = newNode;
        list->end = newNode;
    }else
    {
        Node *node = list->end;
        node->next = newNode;
        list->end = newNode;
    }
}

void LinkedList_remove(LinkedList *list, int value)
{
    if(!is_empty(list))
    {
        if(list->begin->value == value)
        {
            if(list->begin == list->end)
                list->end = NULL;
            Node *node = list->begin;
            list->begin = node->next;
            free(node);            
        } else 
        {
            Node *prevNode = list->begin;
            Node *auxNode = list->begin->next;

            while(auxNode != NULL && auxNode->value != value)
            {
                prevNode = prevNode->next;
                auxNode = auxNode->next;
            }
            if(auxNode != NULL)
            {
                if(auxNode->next == NULL)
                    list->end = prevNode;
                prevNode->next = auxNode->next;
                free(auxNode);
            }else
            printf("Remove error: The value '%d' doesn't exist in List\n", value);
        } 
    }else
    {
        printf("The List is empty");
    }
}

void LinkedList_destroy(LinkedList **list)
{
    Node *node = (*list)->begin;
    Node *auxNode;

    while(node != NULL)
    {
        auxNode = node->next;
        free(node);
        node = auxNode;
    }
    free(*list);
    *list = NULL;
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
    LinkedList_add_last(list, 9);
    LinkedList_print(list);
    puts("");
    puts("");
    LinkedList_remove(list, 13);
    LinkedList_remove(list, 12);
    LinkedList_remove(list, 5);
    LinkedList_remove(list, 111);
    LinkedList_remove(list, 9);
    LinkedList_print(list);
    LinkedList_destroy(&list);
}