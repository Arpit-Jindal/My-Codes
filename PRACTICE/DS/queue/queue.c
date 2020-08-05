#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 100

int queue[CAPACITY], front = -1, rear = -1;

bool isfull()
{
    return rear == CAPACITY;
}

bool isempty()
{
    return front == -1;
}

void insert(int x)
{
    if (isfull())
    {
        printf("QUEUE IS FULL\n");
        return;
    }
    else if (isempty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;

}
void Delete()
{
    if (isempty()) 
        printf("EMPTY QUEUE\n");
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("EMPTY QUEUE\n");
    }
    else
    {
        front = front + 1;
    }
}

void Display()
{
    if (isempty()) printf("EMPTY QUEUE\n");
    else
    {
        int i;
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}
int  main()
{
    int ch;
    while (1) {
        printf("\nQUEUE\n\n1.Insert\n2.Delete\n3.Display\n\nEnter your choice<1-3>: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: int ele;
            printf("enter element: ");
            scanf("%d", &ele); insert(ele);
            break;
        case 2: Delete();
            break;
        case 3: Display();
            break;
        default: printf("INVALID INPUT\n");
        }
    }
}
