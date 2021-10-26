/*Implement a Circular QUEUE using an array.*/
#include <stdio.h>
#define MAX_SIZE 10
int QUEUE[MAX_SIZE];
int Front = -1;
int Rear = -1;
void INSERT(int Data);
void DELETE();
void Print_Queue();
int main()
{
    int E;
    int choice = 1;
    printf("\n--------choose 1 to insert--------- \n");
    printf("\n--------choose 2 to delete--------- \n");
    printf("\n--------choose 3 to display--------- \n");
    while (choice < 4 && choice > 0)
    {
        printf("\n enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n enter the element \n");
            scanf("%d", &E);
            INSERT(E);
            break;
        case 2:
            DELETE();
            break;
        case 3:
            Print_Queue();
        }
    }
    return 0;
}

void INSERT(int Data)
{
    if ((Rear + 1) % MAX_SIZE == Front)
    {
        printf("\n overflow \n");
    }
    else if (Front == -1 && Rear == -1)
    {
        Front = 0;
        Rear = 0;
    }
    else
    {
        Rear = (Rear + 1) % MAX_SIZE;
    }
    QUEUE[Rear] = Data;
}
void DELETE()
{
    if (Front == -1 && Rear == -1)
    {
        printf("\n underflow \n");
    }
    else if (Front == Rear)
    {
        Front = -1;
        Rear = -1;
    }
    else
    {
        Front = (Front + 1) % MAX_SIZE;
    }
}
void Print_Queue()
{
    int i = Front;
    if (Front == -1 && Rear == -1)
    {
        printf("\n Queue is empty \n");
    }
    else
    {
        printf("\n The elements in the QUEUE are \n");
        while (i <= Rear)
        {
            printf("|%d| ", QUEUE[i]);

            i = (i + 1) % MAX_SIZE;
        }
    }
}