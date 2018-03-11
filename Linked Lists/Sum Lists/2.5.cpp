#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

#define LENGTH 5

struct node
{
	int data;
	node* next;
};

node* sumLists(node*, node*);
node* generateLinkedList();
void printLinkedList(node*);


int main()
{
    node* first = generateLinkedList();
	node* second = generateLinkedList();

    printLinkedList(first);
	printLinkedList(second);


	return 0;
}

node* sumLists(node* first, node* second)
{
	if (first == NULL || first == NULL) { return first; }

	std::string firstString  = "";
	std::string secondString = "";

	//	Add all data to strings
	auto head = first;
	if (head->next == NULL) { firstString.append(std::to_string(head->data)); }
	else
	{
		while(head->next != NULL)
		{
			firstString.append(std::to_string(head->data));
			head = head->next;
		}
	}

	head = second;
	if (head->next == NULL) { secondString.append(std::to_string(head->data)); }
	else
	{
		while(head->next != NULL)
		{
			secondString.append(std::to_string(head->data));
			head = head->next;
		}
	}

	std::reverse(std::begin(firstString),  std::end(firstString));
	std::reverse(std::begin(secondString), std::end(secondString));

	//	Turn into int
	//	Add
	//	Turn to string
	//	Reverse
	// Generate Linked List


	return(first);
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
