// This answer is incorrect since I misunderstood the question
// This algorithm deletes the middle node by being given the head
// If size is even will delete second middle node

#include <iostream>
#include <cstdlib>
#include <unordered_set>

#define LENGTH 9

struct node
{
	int data;
	node* next;
};

void deleteMiddleNode(node*);
node* generateLinkedList();
void printLinkedList(node*);

int main()
{
    node* head = generateLinkedList();
    printLinkedList(head);
    deleteMiddleNode(head);
    printLinkedList(head);
}

void deleteMiddleNode(node* head)
{
    if (head == NULL || head->next == NULL)
        return;
    else if (head->next->next == NULL) {
        auto temp = head;
        head = head->next;
        delete temp;
    }

    auto runner      = head->next->next;
    auto current     = head->next;
    auto prevCurrent = head;
    auto secondHop   = false;

    while(runner->next != NULL)
    {
        if ( !secondHop)
        {
            runner = runner->next;
            secondHop = true;
        }
        else
        {
            runner      = runner->next;
            prevCurrent = current;
            current     = current->next;
            secondHop   = false;
        }
    }

    prevCurrent->next = current->next;
    delete current;
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
