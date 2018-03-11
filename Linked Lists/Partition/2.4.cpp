// THIS ANSWER IS INCORRECT

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <deque>

#define LENGTH 10

struct node
{
	int data;
	node* next;
};

void partitionX(node*, auto);
node* generateLinkedList();
void printLinkedList(node*);

int main()
{
    node* head = generateLinkedList();
    printLinkedList(head);
    partitionX(head, 3);
    printLinkedList(head);
}

void partitionX(node* head, auto x)
{
    std::stack<node*> myStack;
    auto current = head;

    while(current->next != NULL)
    {
        if ( current->data < x )
            myStack.push(current);
        current = current->next;
    }

    current = head;

    while(current->next != NULL)
    {
        if ( current->data >= x )
        {
            auto temp = myStack.top();
            myStack.pop();
            auto tempNumber = temp->data;
            temp->data = current->data;
            current->data = tempNumber;
        }
        current = current->next;
    }
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

//3 3 6 2 0 3 0 2
// 7 9
