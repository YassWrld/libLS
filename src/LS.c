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
    new->next = NULL; // Explicitly set the next pointer to NULL
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        Pnode current = *head;
        while (current->next != NULL)
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
    if (*head != NULL)
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

// Deletion functions
void deleteFirst(Pnode *head)
{
    if (*head == NULL)
    {
        fprintf(stderr, "List is already empty. Cannot delete.\n");
        return;
    }

    Pnode temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Pnode *head)
{
    if (*head == NULL)
    {
        fprintf(stderr, "List is already empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        // If there's only one node in the list, delete it
        free(*head);
        *head = NULL;
        return;
    }

    Pnode current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void deleteAfter(Pnode prevNode)
{
    if (prevNode == NULL || prevNode->next == NULL)
    {
        fprintf(stderr, "Cannot delete after the specified node.\n");
        return;
    }

    Pnode temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Utility functions
int getSize(Pnode head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printLinkedList(Pnode head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
