#include <iostream>
#include <cstdlib>
#include <unordered_set>

#define LENGTH 10

struct node
{
	int data;
	node* next;
};

node* kthFromLast(node*, int);
node* generateLinkedList();
void printLinkedList(node*);

int main()
{
    node* head = generateLinkedList();
    printLinkedList(head);
    head = kthFromLast(head, 5);
    printLinkedList(head);
}

node* kthFromLast(node* head, int k)
{
    auto counter = 1;
    bool Synced = false;
    auto start = head, kth = head;

    while(start->next != NULL)
    {
        if (!Synced)
        {
            if (counter == k)
                Synced = true;
            else
                counter++;
            start = start->next;
        }
        else
        {
            start = start->next;
            kth = kth->next;
        }
    }

    return kth;

}



void printLinkedList(node* head)
{
    auto current = head;
    while (current->next != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

node* generateLinkedList()
{
    auto head = new node;
    auto current = head;
    auto temp = new node;


    for(int i = 0; i < LENGTH; i++)
    {
        current->data   = rand() % 10;
        temp->data      = rand() % 10;
        temp->next      = NULL;
        current->next   = temp;
        current         = current->next;
        temp            = new node;
    }

    return head;

}
