#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int a)
    {

        data = a;
        next = NULL;
    }
};

node *generateRandomList(int);
node *generateEvenNumberList(int);
node *generateOddNumberList(int);

void insertAtTail(node *&, int);
void printLinkedList(node *);

int main()
{

    int size = 6;

    node *genHead = generateRandomList(size);

    node *evenHead = generateEvenNumberList(size);

    node *oddHead = generateOddNumberList(size);

    // Pass the desired list in the print function to see results.

    printLinkedList(evenHead);
}


node *generateOddNumberList(int size)
{

    node *head = NULL;

    for (int i = 0; i < size; i++)
    {
        insertAtTail(head, (2 * i + 1));
    }

    return head;
}

node *generateEvenNumberList(int size)
{

    node *head = NULL;

    for (int i = 0; i < size; i++)
    {

        insertAtTail(head, ((i)*2));
    }

    return head;
}

node *generateRandomList(int size)
{

    int a = rand();

    node *head = NULL;

    for (int i = 0; i < size; i++)
    {
        insertAtTail(head, rand());
    }

    return head;
}

void insertAtTail(node *&head, int val)
{

    node *temp = head;
    node *newEl = new node(val);

    if (head == NULL)
    {
        head = newEl;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newEl;
}


void printLinkedList(node *head)
{

    node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}