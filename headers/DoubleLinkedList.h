#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include <iostream>

template <typename type>
class DoubleLinkedList
{
private:
    struct Node
    {
        type data;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = head;
    }

    void addToTail(type val)
    {
        Node *newNode = new Node;

        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addToHead(type val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToIndex(type val, int index)
    {
        if (index < 0)
        {
            std::cerr << "Invalid index." << std::endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (index == 0)
        {
            // Special case: Insert at the head.
            newNode->next = head;
            if (head)
            {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node *temp = head;
        int count = 0;

        while (temp)
        {
            if (count == index - 1)
            {
                if (temp->next) // Ensure temp->next is not nullptr.
                {
                    newNode->next = temp->next;
                    newNode->prev = temp;
                    temp->next->prev = newNode;
                    temp->next = newNode;
                    return;
                }
                else
                {
                    std::cerr << "Index out of bounds." << std::endl;
                    delete newNode; // Clean up the new node if index is out of bounds.
                    return;
                }
            }
            temp = temp->next;
            count++;
        }

        if (!temp && count != index)
        {
            std::cerr << "Index out of bounds." << std::endl;
            delete newNode; // Clean up the new node if index is out of bounds.
        }
    }

    int count()
    {
        int count = 0;
        Node *nodePtr = head;

        while (nodePtr)
        {
            count++;
            nodePtr = nodePtr->next;
        }

        return count;
    }

    type getNth(int index)
    {
        if (index < 0)
        {
            std::cerr << "Invalid index" << std::endl;
            return type();
        }

        Node *nodePtr = head;
        int count = 0;

        while (nodePtr)
        {
            if (count == index)
            {
                if (nodePtr)
                {
                    return nodePtr->data;
                }
                else
                {
                    std::cerr << "Index out of Bounds" << std::endl;
                    return type();
                }
            }
            count++;

            if (nodePtr)
            {
                nodePtr = nodePtr->next;
            }
        }
    }

    type getTail()
    {
        if (tail)
        {
            return tail->data;
        }
        else
        {
            std::cerr << "Tail does not exist" << std::endl;
            return type();
        }
    }

    type pop(int index)
    {
        if (index < 0)
        {
            std::cerr << "Invalid index" << std::endl;
        }
        if (head)
        {
            if (index == 0)
            {
                type val;
                head->data = val;
                Node *temp = head;
                head = head->next;
                if (head)
                {
                    head->prev = nullptr;
                }
                else
                {
                    tail = NULL;
                }
                delete temp;

                return val;
            }

            Node *nodePtr = head;
            int count = 0;

            while (nodePtr)
            {
                if (count == index)
                {
                    if (!nodePtr)
                    {
                        std::cerr << "Index out of bounds" << std::endl;
                    }

                    type val = nodePtr->data;

                    nodePtr->prev->next = nodePtr->next;
                    if (nodePtr->next)
                    {
                        nodePtr->next->prev = nodePtr->prev;
                    }
                    else
                    {
                        tail = nodePtr->prev;
                    }

                    delete nodePtr;

                    return val;
                }
                nodePtr = nodePtr->next;
                count++;
            }

            std::cerr << "Index out of Bounds" << std::endl;
        }
        else
        {
            std::cerr << "List is empty cannot delete" << std::endl;
        }
    }

    void deleteList()
    {
        if (!head)
        {
            std::cout << "There are no elements in list to delete!" << std::endl;
        }

        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void displayList()
    {
        Node *temp = head;
        if (head == NULL)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        if (head)
        {
            return false;
        }

        return true;
    }

    ~DoubleLinkedList()
    {
        std::cout << "\nDestructing List" << std::endl;
        deleteList();
    }
};

#endif