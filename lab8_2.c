/*Create a Complete Binary Tree made up of all the alphabets (A to Z) using Linked List. A is the
root of the tree. B and C will be the left and right children of A, respectively, and so on. Write
the recursive functions for Pre-Order, In-Order and Post-Order traversals to print the elements
in the Tree.*/

#include <stdio.h>
#include <stdlib.h>

// For Queue Size
#define MAX_SIZE 30

// A tree node
struct Tree
{
    struct Tree *left_node;
    char data;
    struct Tree *right_node;
};

// A queue node
struct Queue
{
    int front;
    int rear;
    int size;
    struct Tree **array;
};

// A utility function to create a new tree node
struct Tree *New_Node(char data)
{
    struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->data = data;
    temp->left_node = NULL;
    temp->right_node = NULL;
    return temp;
}

// A utility function to create a new Queue
struct Queue *create_Queue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->front = -1;
    queue->rear = -1;
    queue->size = size;

    queue->array = (struct Tree **)malloc(queue->size * sizeof(struct Tree *));

    for (int i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

void Enqueue(struct Tree *root, struct Queue *queue)
{
    if (queue->rear == queue->size - 1)
        return;

    queue->array[++queue->rear] = root; /* inserting tree node into queue */

    if (queue->front == -1)
        ++queue->front;
}

struct Tree *Dequeue(struct Queue *queue)
{
    if (queue->front == -1)
        return NULL;

    struct Tree *temp = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
        ++queue->front;

    return temp; /* returning deleted node */
}

int has_Both_Child(struct Tree *temp)
{
    return temp && temp->left_node && temp->right_node;
}

void insert(struct Tree **root, char data, struct Queue *queue)
{
    struct Tree *temp = New_Node(data);

    // If the tree is empty, initialize the root with new node.
    if (!*root)
        *root = temp;

    else
    {
        // get the front node of the queue.
        struct Tree *front = queue->array[queue->front];

        // If the left child of this front node doesn’t exist, set the
        // left child as the new node
        if (!front->left_node)
            front->left_node = temp;

        // If the right child of this front node doesn’t exist, set the
        // right child as the new node
        else if (!front->right_node)
            front->right_node = temp;

        // If the front node has both the left child and right child,
        // Dequeue() it.
        if (has_Both_Child(front))
            Dequeue(queue);
    }
    // Enqueue() the new node for later insertions
    Enqueue(temp, queue);
}

// Standard pre order traversal to test above function
void Pre_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    printf("%c ", ptr->data);

    Pre_order(ptr->left_node);

    Pre_order(ptr->right_node);
}
// Standard in order traversal to test above function
void In_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    In_order(ptr->left_node);

    printf("%c ", ptr->data);

    In_order(ptr->right_node);
}
// Standard post order traversal to test above function
void Post_order(struct Tree *ptr)
{
    if (ptr == NULL)
        return;

    Post_order(ptr->left_node);

    Post_order(ptr->right_node);

    printf("%c ", ptr->data);
}

// Driver program to test above functions
int main()
{
    struct Tree *root = NULL;
    struct Queue *queue = create_Queue(MAX_SIZE);

    for (char i = 65; i <= 90; ++i)
        insert(&root, i, queue);

    printf("----Inserted alphabets are in the order of----\n");
    for (char j = 65; j <= 90; j++)
        printf("%c ", j);
    printf("\n");

    printf("----preorder trversal of alphabets from (A-Z)----\n ");
    Pre_order(root);
    printf("\n");
    printf("----inorder trversal of alphabets from (A-Z)----\n ");
    In_order(root);
    printf("\n");
    printf("----postorder trversal of alphabets from (A-Z)----\n ");
    Post_order(root);
    printf("\n");

    return 0;
}