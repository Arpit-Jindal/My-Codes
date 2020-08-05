#include<iostream>
using namespace std;
#define n 100

class cqueue
{
    int a[n];
    int front, rear;
public:
    cqueue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return front == (rear + 1) % n;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        a[rear] = x;

    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is already Empty\n";
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
            cout << "Queue is now empty\n";
        }
        else
        {
            cout << "Removing " << a[front] << endl;
            front = (front + 1) % n;
        }

    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            int count = (rear - front + n) % n + 1;
            cout << "Queue : ";

            for (int i = 0; i < count; i++)
            {
                cout << a[(front + i) % n] << " ";
            }
            cout << "\n\n";
        }
    }

};

int main()
{
    cqueue q;

    while (1) {
        cout << "CIRCULAR QUEUE\n\n1.Insert\n2.Remove\n3.Print\n4.Exit\nEnter your choice: ";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1: cout << "Enter element to push: ";
            int x;
            cin >> x;
            q.push (x);
            break;
        case 2: q.pop();
            break;
        case 3: q.print();
            break;
        case 4: return 0;
        default: cout << "INVALID INPUT\n\n";
        }
    }
}
