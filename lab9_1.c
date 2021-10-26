/*Create a doubly Linked List (Two-way Linked List) from the Calander month names (January,
February, March........December). Convert this to it's corresponding balanced Binary Search
Tree (BST). Perform the In-order traversal.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct DLL
{
    struct DLL *prev;
    char *Month;
    struct DLL *next;
};

struct DLL *head = NULL;
struct DLL *tail = NULL;

void Create_doubly_linked_list(char *str)
{
    struct DLL *new_node = (struct DLL *)malloc(sizeof(struct DLL));
    new_node->Month = (char *)malloc(sizeof(char) * (strlen(str) + 1)); /* giving memory to this string */
    strcpy(new_node->Month, str);                                       /*copying the data of given string*/
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        tail = head;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = tail->next;
    }
}

void print_list()
{
    struct DLL *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%s <=> ", temp->Month);
        temp = temp->next;
    }
    printf("\n");
}

void Create_BST(struct DLL *h, struct DLL *t, struct DLL **root)
{
    struct DLL *f = h;
    struct DLL *r = t;
    if (f == NULL || r == NULL)
        return;
    else
    {
        while (f != r) /* this loop gives the middle node of linked list */
        {
            if (f == r || f == r->prev)
                break;
            f = f->next;
            r = r->prev;
        }
        *root = r;
        if ((*root)->prev != NULL)
            (*root)->prev->next = NULL;
        if ((*root)->next != NULL)
            (*root)->next->prev = NULL;
        Create_BST(h, r->prev, &((*root)->prev)); /* recursion step for left sub tree */
        Create_BST(r->next, t, &((*root)->next)); /* recursion step for right sub tree */
    }
}

void inorder(struct DLL *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->prev);
        printf(" %s ", root->Month);
        inorder(root->next);
    }
}

int main()
{
    struct DLL *root = NULL;
    Create_doubly_linked_list("January");
    Create_doubly_linked_list("February");
    Create_doubly_linked_list("March");
    Create_doubly_linked_list("April");
    Create_doubly_linked_list("May");
    Create_doubly_linked_list("June");
    Create_doubly_linked_list("July");
    Create_doubly_linked_list("August");
    Create_doubly_linked_list("September");
    Create_doubly_linked_list("October");
    Create_doubly_linked_list("November");
    Create_doubly_linked_list("December");
    printf("---------------------Taken Doubly linked list is---------------------------\n");
    print_list();
    printf("----------------------------------------------------------------------------\n");

    Create_BST(head, tail, &root);
    printf("------- As the number of nodes will be even we take July as Root node------\n");
    printf("----------------------------------------------------------------------------\n");
    printf("---------------------inorder traversal of Balanced BST----------------------\n");
    inorder(root);
    printf("\n");

    return 0;
}