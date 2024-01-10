/*
    Author: Devakrishnan G
    Problem Statement: Write a C program to perform
                Create
                Display
                Search
                Delete
                Update
                Insert
                Exit

            operations in Array
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int N;
    int *Array;
    bool Empty;
};

// CREATE
void Create(struct node *Node)
{

    printf("Enter the Limit: ");
    scanf("%d", &Node->N);

    Node->Array = (int *)malloc(Node->N * sizeof(int));
    for (int i = 0; i < Node->N; i++)
    {
        printf("Enter the value of Array[%d]: ", i);
        scanf("%d", &Node->Array[i]);
    }

    if (Node->N > 0)
    {
        Node->Empty = false;
    }

    printf("\nArray Created Successfully");
}

// DISPLAY
void Display(struct node *Node)
{
    if (Node->Empty)
    {
        printf("The Array is Empty");
    }
    else
    {
        printf("[");
        for (int i = 0; i < Node->N; i++)
        {
            printf("%d", Node->Array[i]);

            if (i < (Node->N - 1))
            {
                printf(", ");
            }
        }
        printf("]");
    }
}

// SEARCH
int Search(struct node *Node, int element)
{
    for (int i = 0; i < Node->N; i++)
    {
        if (Node->Array[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// DELETE
void Delete(struct node *Node)
{
    if (Node->Empty)
    {
        printf("The Array is Empty");
    }
    else
    {
        int element, position;
        printf("Enter the element to delete: ");
        scanf("%d", &element);

        position = Search(Node, element);

        if (position == -1)
        {
            printf("The element is not present in the Array");
        }
        else
        {
            for (int i = position; i < Node->N; i++)
            {
                Node->Array[i] = Node->Array[i + 1];
            }
            Node->N = Node->N - 1;

            if (Node->N == 0)
            {
                Node->Empty = true;
            }

            printf("\nThe Element is Deleted Successfully");
        }
    }
}

// UPDATE
void Update(struct node *Node)
{
    if (Node->Empty)
    {
        printf("The Array is Empty");
    }
    else
    {
        int old_element, new_element, position;

        printf("Enter the Element to update: ");
        scanf("%d", &old_element);
        position = Search(Node, old_element);

        if (position == -1)
        {
            printf("The element is not present in the Array");
        }
        else
        {
            printf("Enter the new element to Update: ");
            scanf("%d", &new_element);
            Node->Array[position] = new_element;
            printf("The Element is Updated Successfully");
        }
    }
}

// INSERT
void Insert(struct node *Node)
{
    int new_element, position;
    printf("Enter the Index Number to insert in an Array: ");
    scanf("%d", &position);
    printf("Enter the new element to insert in an Array: ");
    scanf("%d", &new_element);

    Node->N = Node->N + 1;
    Node->Array = (int *)realloc(Node->Array, Node->N * sizeof(int));

    for (int i = Node->N - 1; i > 1; i--)
    {
        if (i != position)
        {
            Node->Array[i] = Node->Array[i - 1];
        }
        else
        {
            Node->Array[i] = new_element;
            printf("Inserted Successfully");
            break;
        }
    }
}

int main()
{
    int op;
    bool entry = true;
    struct node node;
    struct node *Node = &node;
    Node->Empty = true;

    while (entry)
    {
        printf("\n\n1. Create\n2. Display\n3. Search\n4. Delete\n5. Update\n6. Insert\n7. Exit\nEnter Your Choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Create(Node);
            break;
        case 2:
            Display(Node);
            break;
        case 3:
            if (Node->Empty)
            {
                printf("The Array is Empty");
            }
            else
            {
                int element, position;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = Search(Node, element);

                if (position != -1)
                {
                    printf("\nThe Element is present in the position %d of Array", position);
                }
                else
                {
                    printf("The element is not present in the Array");
                }
            }
            break;
        case 4:
            Delete(Node);
            break;
        case 5:
            Update(Node);
            break;
        case 6:
            Insert(Node);
            break;
        case 7:
            entry = false;
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }

    return 0;
}