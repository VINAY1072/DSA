/*Create an integer Binary Tree (height>=3) of your choice using Linked List. Fill the integers
randomly. After creation of the Tree, Write the recursive functions for Pre-Order, In-Order and
Post-Order traversals. While traversing, find the Mean and Standard Deviation of the elements
in the tree.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Tree
{
    struct Tree *left_node;
    int data;
    struct Tree *right_node;
};

struct Tree *root = NULL;
static int sum = 0, count = 0, sum_of_squares = 0;
struct Tree *create_node(int data)
{
    struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->left_node = NULL;
    temp->data = data;
    temp->right_node = NULL;

    return temp;
}

void Pre_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    printf("%d ", ptr->data);

    Pre_order(ptr->left_node);

    Pre_order(ptr->right_node);
}

void In_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    In_order(ptr->left_node);

    printf("%d ", ptr->data);

    In_order(ptr->right_node);

    sum = sum + ptr->data;
    sum_of_squares = sum_of_squares + (ptr->data * ptr->data);
    count++;
}

void Post_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    Post_order(ptr->left_node);

    Post_order(ptr->right_node);

    printf("%d ", ptr->data);
}

int main()
{
    time_t taken;
    srand((unsigned)time(&taken));
    float Mean = 0.0, standard_deviation = 0.0;

    printf("-----Entered node are----\n");
    root = create_node(rand() % 10);
    printf("%d ", root->data);
    root->left_node = create_node(rand() % 10);
    printf("%d ", root->left_node->data);
    root->right_node = create_node(rand() % 10);
    printf("%d ", root->right_node->data);
    root->left_node->left_node = create_node(rand() % 10);
    printf("%d ", root->left_node->left_node->data);
    root->left_node->right_node = create_node(rand() % 10);
    printf("%d ", root->left_node->right_node->data);
    root->right_node->left_node = create_node(rand() % 10);
    printf("%d ", root->right_node->left_node->data);
    root->right_node->right_node = create_node(rand() % 10);
    printf("%d ", root->right_node->right_node->data);
    root->left_node->left_node->left_node = create_node(rand() % 10);
    printf("%d ", root->left_node->left_node->left_node->data);

    printf("\n");

    printf("----preorder trversal----\n ");
    Pre_order(root);
    printf("\n");
    printf("----inorder trversal----\n ");
    In_order(root);
    printf("\n");
    printf("----postorder trversal----\n ");
    Post_order(root);
    printf("\n");

    Mean = (float)sum / count;
    standard_deviation = (float)sqrt((sum_of_squares / count) - (Mean * Mean));

    printf("----Mean of the Elements----\n");
    printf("%.2f\n", Mean);

    printf("----standard deviation of the Elements----\n");
    printf("%.2f\n", standard_deviation);

    return 0;
}