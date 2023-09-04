

#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct queue
{

    char queue[MaxSize];
    int QpointerFront = -1;
    int QpointerRear = -1;
} qu;

void printQueue(qu *q5)
{
    for (int i = 0; i < MaxSize; i++)
    {
        cout << q5->queue[i] << endl;
    }
}
int isQueueFull(qu *q2)
{
    if (q2->QpointerRear == MaxSize - 1)
    {
        cout << "Queue is full " << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isQueueEmpty(qu *q4)
{
    if (q4->QpointerRear == -1)
    {
        cout << "Queue empty! " << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(qu *q1, auto val)
{
    if (isQueueFull(q1))
    {
        return 0;
    }
    else
    {
        q1->QpointerRear++;
        // q1->QpointerFront++;

        q1->queue[q1->QpointerRear] = val;
        return 1;
    }
}
int dequeue(qu *q3)
{
    int result;
    if (isQueueEmpty(q3))
    {
        q3->QpointerFront = -1;
        q3->QpointerRear = -1;
        return 0;
    }
    q3->QpointerFront++;

    q3->queue[q3->QpointerFront] = 0;
}
int main()
{
    qu *qq = new queue();
    enqueue(qq, 'a');
    enqueue(qq, 'b');
    enqueue(qq, 'c');
    enqueue(qq, 'd');
    enqueue(qq, 'e');
    enqueue(qq, 'f');
    enqueue(qq, 'g');
    enqueue(qq, 'h');
    enqueue(qq, 'i');
    enqueue(qq, 'j');


    dequeue(qq);
    dequeue(qq); // dequeueing or setting first 3 values to 0
    dequeue(qq);
    printQueue(qq);
    return 0;
}