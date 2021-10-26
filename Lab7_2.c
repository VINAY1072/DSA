#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct stack
{
    char data;
    struct stack *link;
};

struct stack *top = NULL;
struct stack *next(char Data);
int GetOperatorWeight(char op);
int IsOperand(char C);
char *InfixToPostfix(char expression[]);
char *reverse(char expression[]);
char *prefix(char expression[]);
void push(struct stack **top, char Data);
char pop(struct stack **top);
int empty(struct stack *top);
int Evaluation_of_prefix(char expression[]);
int main()
{
    char s[1000];
    printf("\n Enter the string \n");
    scanf("%s", s);
    printf("The prefix is: %s\n", prefix(s));
    printf("\n Final result is %d\n", Evaluation_of_prefix(s));
    return 0;
}
int GetOperatorWeight(char op)

{
    switch (op)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return -1;
}

int IsOperand(char C)
{
    return (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z') || (C >= '0' && C <= '9');
}

char *InfixToPostfix(char expression[])
{
    int i, j = 0;
    struct stack *ptr = NULL;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (IsOperand(expression[i]))
        {
            expression[j++] = expression[i];
        }
        else if (expression[i] == ')')
        {
            push(&ptr, expression[i]);
        }
        else if (expression[i] == '(')
        {
            while (!empty(ptr) && ptr->data != ')')
                expression[j++] = pop(&ptr);
            if (!empty(ptr) && ptr->data != ')')
                return 0;
            else
                pop(&ptr);
        }
        else
        {
            while (!empty(ptr) &&
                   GetOperatorWeight(expression[i]) <= GetOperatorWeight(ptr->data))
            {

                expression[j++] = pop(&ptr);
            }
            push(&ptr, expression[i]);
        }
    }
    while (!empty(ptr))
    {
        expression[j++] = pop(&ptr);
    }
    expression[j++] = '\0';

    return expression;
}
char *reverse(char expression[])
{
    int i, j;
    for (j = 0; expression[j] != '\0'; j++)
        ;
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    for (i = 0; i < j; i++)
    {
        push(&ptr, expression[i]);
    }
    for (i = 0; i < j; i++)
    {
        expression[i] = pop(&ptr);
    }
    if (expression[i] == '(')
    {
        expression[i] = ')';
    }
    else if (expression[i] == ')')
    {
        expression[i] = '(';
    }
    return expression;
}
char *prefix(char expression[])
{
    expression = reverse(expression);
    expression = InfixToPostfix(expression);
    expression = reverse(expression);
    return expression;
}
int Evaluation_of_prefix(char expression[])
{
    for (int i = strlen(expression) - 1; i >= 0; i--)
    {
        if (IsOperand(expression[i]))
        {
            push(&top, expression[i] - '0');
        }
        else
        {
            int o1 = pop(&top);

            int o2 = pop(&top);
            switch (expression[i])
            {
            case '+':
                push(&top, o1 + o2);
                break;
            case '-':
                push(&top, o1 - o2);
                break;
            case '*':
                push(&top, o1 * o2);
                break;
            case '/':
                push(&top, o1 / o2);
                break;
            }
        }
    }
    return pop(&top);
}

struct stack *next(char Data)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = Data;
    temp->link = NULL;
    return temp;
}
void push(struct stack **top, char Data)
{
    struct stack *temp = next(Data);
    temp->link = *top;
    *top = temp;
}
char pop(struct stack **top)
{
    char c;
    if (empty(*top))
    {
        return 0;
    }
    struct stack *temp = *top;
    *top = (*top)->link;
    c = temp->data;
    free(temp);
    return c;
}
int empty(struct stack *top)
{
    return top == NULL;
}