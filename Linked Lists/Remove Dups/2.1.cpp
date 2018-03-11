#include <iostream>
#include <cstdlib>
#include <unordered_set>

#define LENGTH 10

struct node
{
	int data;
	node* next;
};

void removeDuplicates(node*);
node* generateLinkedList();
void printLinkedList(node*);

int main()
{
    node* head = generateLinkedList();
    printLinkedList(head);
    removeDuplicates(head);
    printLinkedList(head);
}

void removeDuplicates(node* head)
{
	std::unordered_set<int> set;
    auto current = head;
    auto prev    = current;

    while(current->next != NULL)
    {
		//	We only move previous if number doesn't exist in hashSet
		//	Otherwise algorithm doesn't catch contigious duplicates
        if (set.count(current->data) > 0)
        {
            prev->next = current->next;
			current = current->next;
        }
        else
        {
            set.insert(current->data);
			prev = current;
	        current = current->next;
        }


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
