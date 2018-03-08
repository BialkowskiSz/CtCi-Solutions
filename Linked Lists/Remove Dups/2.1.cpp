#import <iostream>
#import <cstdlib>

#define LENGTH 50

using namespace std;

struct node
{
	int data;
	node* next;
};

void removeDuplicates(node*);

int main()
{
	node* head = new node;
	head->data = 5;
	head->next = NULL;

	removeDuplicates(head);


}

void removeDuplicates(node* head) {
	cout << head->data << endl;
}
