#ifndef STACK
#define STACK
#include "D:\study\Practice\C++\Linked Lists\DoubleLinkedList.h"

template <typename type>
class Stack
{
private:
    int size;
    int top;
    bool __linked_list_check__;
    type *stack;
    DoubleLinkedList<type> LinkedStack;

public:
    Stack(int size = 0, bool useLinkedList = false)
    {
        if (useLinkedList)
        {
            LinkedStack = DoubleLinkedList<type>();
            __linked_list_check__ = true;
        }
        else
        {
            this->size = size;
            stack = new type[size];
            top = -1;
            __linked_list_check__ = false;
        }
    }

    bool isEmpty()
    {
        if (__linked_list_check__)
        {
            if (LinkedStack.isEmpty())
            {
                return false;
            }

            return true;
        }

        return top < 0;
    }

    bool isFull()
    {
        if (__linked_list_check__)
        {
            return false;
        }

        return top >= size;
    }

    type pop()
    {
        if (__linked_list_check__)
        {
            int index = LinkedStack.count() - 1;
            return LinkedStack.pop(index);
        }

        if (!isEmpty())
        {
            type data = stack[top];
            stack[top--] = -1;
            return data;
        }
        else
        {
            std::cerr << ("Stack is empty") << std::endl;
        }
    }

    void push(type data)
    {
        if (__linked_list_check__)
        {
            LinkedStack.addToTail(data);
            return;
        }
        else
        {
            if (!isFull())
            {
                stack[++top] = data;
                return;
            }
            else
            {
                std::cerr << ("Stack is full") << std::endl;
            }
        }
    }

    type peek()
    {
        if (__linked_list_check__)
        {
            return LinkedStack.getTail();
        }

        else if (!isEmpty())
        {
            return stack[top];
        }
        else
        {
            std::cerr << ("Stack is full") << std::endl;
            return type();
        }
    }

    ~Stack()
    {
        if (__linked_list_check__)
        {
            LinkedStack.~DoubleLinkedList();
        }
        else
        {
            delete[] stack;
        }
    }
};

#endif