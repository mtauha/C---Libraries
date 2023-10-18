#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

template <typename type>
class LinkedList
{
private:
    struct Node
    {
        type data;
        Node *next;
        Node(type val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void add(type value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *nodePtr = head;
            while (nodePtr->next)
            {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
        }
    }

    void addAtStart(type value)
    {
        Node *newHead = new Node(value);
        newHead->next = head;
        head = newHead;
    }

    bool addAtIndex(int index, type value)
    {
        if (index < 0)
        {
            std::cerr << "Invalid index." << std::endl;
            return false;
        }

        if (index == 0)
        {
            addAtStart(value);
            return true;
        }

        Node *nodePtr = head;
        Node *newNode = new Node(value);

        int count = 0;
        while (count != (index - 1) && nodePtr)
        {
            nodePtr = nodePtr->next;
            count++;
        }

        if (!nodePtr)
        {
            std::cerr << "Index out of bounds." << std::endl;
            delete newNode; // Clean up the new node.
            return false;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
        return true;
    }

    void displayList()
    {
        Node *current = head;
        while (current)
        {
            if (current->next == nullptr)
            {
                std::cout << current->data;
                break;
            }
            else
            {
                std::cout << current->data << ", ";
                current = current->next;
            }
        }
    }

    void deleteList()
    {
        while (head)
        {
            Node *current = head;
            head = head->next;
            delete current;
        }
    }

    bool editFirstList(type Old, type New)
    {
        Node *ptr = head;

        while (ptr)
        {
            if (ptr->data == Old)
            {
                ptr->data = New;
                return true;
            }
            ptr = ptr->next;
        }

        std::cout << Old << " not found in the list." << std::endl;
        return false;
    }

    void editAllList(type Old, type New)
    {
        Node *ptr = head;

        while (ptr)
        {
            if (ptr->data == Old)
            {
                ptr->data = New;
            }

            ptr = ptr->next;
        }
    }

    void reverse()
    {
        Node *tempNext;
        Node *newHead = nullptr;

        while (head)
        {
            tempNext = head->next;
            head->next = newHead;
            newHead = head;
            head = tempNext;
        }

        head = newHead;
    }
};

#endif
