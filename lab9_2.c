/*Create a Binary Search Tree (BST) from random N numbers. N should be taken as input from
the user. Using the same N numbers, create the corresponding AVL tree. Show the height
difference between both these trees (BST vs AVL).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Tree
{
    struct Tree *left;
    int data;
    int height;
    struct Tree *right;
};

struct Tree *newNode(int Data)
{
    struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->data = Data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

int max_num(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int Height(struct Tree *r) /*returns the height value*/
{
    if (r == NULL)
        return 0;

    else
        return r->height;
}

struct Tree *insert(struct Tree *root, int Data)
{
    if (root == NULL)
        return newNode(Data);

    if (Data < root->data)
        root->left = insert(root->left, Data);
    else if (Data > root->data)
        root->right = insert(root->right, Data);

    root->height = 1 + max_num(Height(root->left), Height(root->right));

    return root;
}

struct Tree *rightRotate(struct Tree *y)
{
    struct Tree *x = y->left;
    struct Tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max_num(Height(y->left), Height(y->right)) + 1;
    x->height = max_num(Height(x->left), Height(x->right)) + 1;

    return x;
}

struct Tree *leftRotate(struct Tree *x)
{
    struct Tree *y = x->right;
    struct Tree *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max_num(Height(x->left), Height(x->right)) + 1;
    y->height = max_num(Height(y->left), Height(y->right)) + 1;

    return y;
}

int getBalance(struct Tree *N)
{
    if (N == NULL)
        return 0;
    return Height(N->left) - Height(N->right); /* balance property of AVL tree */
}

int sum = 0;
void fun(struct Tree *ptr)
{
    int temp;
    if (ptr == NULL)
        return;
    fun(ptr->right);
    temp = ptr->data;
    ptr->data = sum;
    sum = sum + temp;
    fun(ptr->left);
}

struct Tree *insert_AVL(struct Tree *root, int Data)
{
    if (root == NULL)
        return newNode(Data);

    if (Data < root->data)
        root->left = insert_AVL(root->left, Data);
    else if (Data > root->data)
        root->right = insert_AVL(root->right, Data);

    root->height = 1 + max_num(Height(root->left), Height(root->right)); /*updating height of avl tree*/
    int balance = getBalance(root);

    if (balance > 1 && Data < root->left->data) /*RR rotation*/
        return rightRotate(root);

    if (balance < -1 && Data > root->right->data) /*LL rotation*/
        return leftRotate(root);

    if (balance > 1 && Data > root->left->data) /* LR rotation */
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && Data < root->right->data) /* RL rotation */
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    srand(time(NULL));
    struct Tree *root = NULL;
    struct Tree *root_1 = NULL;
    int N, i, j;
    printf("-----Enter the size of array----\n");
    scanf("%d", &N);
    int node[N];
    printf("----entered elements are--------\n");

    for (i = 0; i < N; i++)
    {
        scanf("%d", &node[i]);
        root = insert(root, node[i]);
        printf("%d ", node[i]);
    }
    printf("\n");
    fun(root);
    printf("=============Inorder Traversal of BST============\n");
    inorder(root);
    printf("\n");

    for (i = 0; i < N; i++)
    {
        root_1 = insert_AVL(root_1, node[i]);
    }
    printf("*****************AVL TREE IS CREATED**************\n");
    printf("===========Inorder Traversal of AVL tree=========\n");
    inorder(root_1);
    printf("\n");
    printf("--------Height of BSL-|-Height of AVL--------- \n");
    printf("              %d       |        %d               \n", root->height, root_1->height);
    printf("                      |                         \n");

    return 0;
}
