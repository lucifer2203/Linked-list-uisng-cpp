#include<iostream>
using namespace std;

class IsolatedNode {
public:
	int data;
	IsolatedNode* next;
};

int printLL(IsolatedNode* n) {
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}
int main() {	
	IsolatedNode* head = NULL;
	IsolatedNode* first = NULL;
	IsolatedNode* second = NULL;

	head = new IsolatedNode();
	first = new IsolatedNode();
	second = new IsolatedNode();

	head->data = 100;
	head->next = first;

	first->data = 200;
	first->next = second;

	second->data = 300;
	second->next = NULL;


	printLL(head);
}
