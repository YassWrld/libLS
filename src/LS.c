#include <stdio.h>
#include <stdlib.h>
#include "LS.h"

// Initialization functions
Pnode createNode(int data)
{
    Pnode newNode = (Pnode)malloc(sizeof(node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion functions
void insertFirst(Pnode *head, int data)
{
    Pnode new = createNode(data);
    new->data = data;
    new->next = *head;
    *head = new;
}

void insertLast(Pnode *head, int data)
{
    Pnode new = createNode(data);
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        Pnode current = *head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = new;
    }
}

void insertAfter(Pnode prevNode, int data)
{
    if (prevNode == NULL)
    {
        fprintf(stderr, "Previous node cannot be NULL.\n");
        return;
    }

    Pnode new = createNode(data);
    new->data = data;
    new->next = prevNode->next;
    prevNode->next = new;
}

void insertBefore(Pnode *head, Pnode targetNode, int data)
{
    if (*head = NULL)
    {
        fprintf(stderr, "List is empty. Cannot insert before.\n");
        return;
    }

    if (*head == targetNode)
    {
        Pnode new = createNode(data);
        new->next = *head;
        *head = new;
    }
    else
    {
        Pnode current = *head;
        while (current->next != NULL && current->next != targetNode)
        {
            current = current->next;
        }
        if (current->next == targetNode)
        {
            Pnode new = createNode(data);
            new->next = current->next; // or = targetNode
            current->next = new;
        }
        else
        {
            fprintf(stderr, "Target node not found in the list.\n");
        }
        }
}