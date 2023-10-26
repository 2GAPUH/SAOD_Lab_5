#include "Stack.h"

bool Stack::CheckEmpty()
{
    return head;
}

void Stack::Clear()
{
    while (CheckEmpty())
    {
        Delete();
    }
}

void Stack::Push(int& n)
{
    if (CheckEmpty())
    {
        Element* tmp = new Element;
        tmp->prev = head;
        head = tmp;
        head->data = n;
    }
    else
    {
        head = new Element;
        head->data = n;
    }
}

void Stack::Delete()
{
    if (CheckEmpty())
    {
        if (head->prev)
        {
            Element* tmp = head;
            head = head->prev;
            delete tmp;
        }
        else
        {
            delete head;
            head = nullptr;
        }
    }
}

int Stack::GetElement()
{
    if (CheckEmpty())
    {
        return head->data;
    }
    return 0;
}

Stack::~Stack()
{
    if (CheckEmpty())
    {
        Clear();
    }
}

