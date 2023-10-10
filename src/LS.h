#pragma once

#ifndef LS_H
#define LS_H

typedef struct node *Pnode;
typedef struct node
{
    int data;
    Pnode next;
} node;

// Initialization functions
Pnode createNode(int data);

// Insertion functions
void insertFirst(Pnode *head, int data);
void insertLast(Pnode *head, int data);
void insertAfter(Pnode prevNode, int data);
void insertBefore(Pnode *head, Pnode targetNode, int data);

// Deletion functions
void deleteFirst(Pnode *head);
void deleteLast(Pnode *head);

// Utility functions
int getSize(Pnode head);
void printLinkedList(Pnode head);

#endif