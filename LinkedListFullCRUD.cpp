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

void insertAtHead(node *&head, int val)
{

    node *newEl = new node(val);

    newEl->next = head;
    head = newEl;
}

void insertAtTail(node *&head, int val)
{

    node *newEl = new node(val);

    node *temp = head;

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

void deleteAtHead(node *&head)
{

    node *temp = head;

    head = head->next;

    delete (temp);
}

void deleteAtPosition(node *&head, int __pos)
{

    node *temp = head;

    int count = 0;

    if (__pos == 0)
    {
        deleteAtHead(head);
        return;
    }
    else if (__pos < 0)
    {
        cout << "Please pass a valid position";
        return;
    }

    while (count != __pos - 1)
    {

        if (temp == NULL)
        {
            cout << "Position is out of bound!";
            return;
        }

        temp = temp->next;
        count++;
    }

    if (count == __pos - 1)
    {

        node *toDelete = temp->next;

        temp->next = toDelete->next;

        delete toDelete;
    }
}

void updateAtPosition(node *&head, int pos, int val)
{

    node *temp = head;
    int count = 0;

    if (pos < 0)
    {
        cout << "Please pass a valid position!";
        return;
    }

    while (count != pos)
    {

        if (temp == NULL)
        {
            cout << "Position is out of bound!";
            return;
        }

        temp = temp->next;
        count++;
    }

    temp->data = val;
}

node *createRandomList(int size)
{

    int randm = rand();

    node *head = new node(randm);

    for (int i = 0; i < size - 1; i++)
    {
        int rand2 = rand();

        insertAtTail(head, rand2);
    }

    return head;
}

int main()
{

    /**
     * Below is the demonstration on how to use this code.
     * 1. Creating a linked list manually.
     * 2. Updating the value of the linked list at any position.
     * 3. Deleting the value of the linked list at any position.
     * 4. Creating a linked list with random values of defined size.
     * 5. Printing the linked list.
     *
     * NOTE: If you print the linked list to check the result of
     * a particular part of the code, then you should comment all the other
     * parts below that which could disturb the code.
     */

    /** 1. Creating the linked ist manually. */

    node *head = NULL; // Assign a head

    insertAtTail(head, 1); // Insert elements at the tail of linked list
    insertAtTail(head, 2);

    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 6); // Insert elements at the head of linked list

    // You can print the list here to check the result.

    /** 2. Updating the value of the linked list at any position. */

    updateAtPosition(head, 3, 40); // updating the above created linked list.

    /** 3. Deleting the value of the linked list at any position. */

    deleteAtPosition(head, 2); // Delete at any position.

    deleteAtHead(head);  //Delete sepcifically at head.

    // /** 4. Creating a linked list with random values of defined size. */

    node *generatedHead = createRandomList(10); //Pass the size value in the function.

        //above function returns the head for the generated list, which is 
        //stored in the generatedHead variable : Type - Pointer.


    /** 5. Printing the linked list. */


    printLinkedList(head); //printing the manually created list.

    printLinkedList(generatedHead); //printing the generated list.

    return 0;
}