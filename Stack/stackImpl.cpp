#include <iostream>
using namespace std;

#define MAX 10
int siZe = 0;
typedef struct stack
{
    char stackSize[MAX];
    int stackPointer = -1;
} ST;
void printStack(ST *s)
{
    for (int i = s->stackPointer; i >= 0; i--)
    {
        cout << "Stack element is: " << s->stackSize[i] << endl;
    }
}
int checkStackEmpty(ST *st)
{
    if (st->stackPointer == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkStackFull(ST *St)
{
    if (St->stackPointer == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int popStackElement(ST *ST)
{
    char returnStackElement = 0;
    if (checkStackEmpty(ST))
    {
        cout << "Stack empty lol";
    }
    {
        returnStackElement = ST->stackSize[ST->stackPointer];
        ST->stackPointer--;
    }
    siZe--;
    cout << endl;
    return returnStackElement;
}
int pushStackElement(ST *st, char val)
{
    if (checkStackFull(st))
    {
        cout << "stack is full ";
    }
    else
    {
        st->stackPointer++;
        st->stackSize[st->stackPointer] = val;
    }
    siZe++;
    return 0;
}
int main()
{
    ST *s = new ST();
    s->stackPointer = -1;
    string rev = "Jasper";
    for (int i = 0; i < rev.length(); i++)
    {
        pushStackElement(s, rev[i]);
    }

    printStack(s);
    return 0;
}