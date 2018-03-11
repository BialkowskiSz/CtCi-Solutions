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
	int input;

    printLinkedList(head);
	std::cout << "Enter partition number: ";
	std::cin >> input;

    partitionX(head, input);
    printLinkedList(head);
	return 0;
}

void partitionX(node* head, auto x)
{
    std::stack<node*> myStack;
    auto current = head;

    while(current->next != NULL)
	{
		if (current->data < x)
			myStack.push(current);
		current = current->next;
	}

	auto size = myStack.size();
	current = head;
	for (size_t i = 0; i < size; i++)
	{
		if (current->data >= x)
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
    auto temp = new node {0, NULL};

    for(int i = 0; i < LENGTH; i++)
    {
        current->data = rand() % 10;
		current->next = temp;
		temp = new node{0, NULL};
		current = current->next;
    }

    return head;

}
