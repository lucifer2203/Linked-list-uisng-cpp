#include<iostream>
#include<climits>
using namespace std;

class node {
public:
	int data;
	node* next;
	
	node() {
		this->data = NULL;
		this->next = NULL;
	}

	node(int data) {
		this->data = data;
		this->next=NULL;
	}
};

void inserttail(node* &head,int data) {
	node* n = new node(data);

	if (head == NULL) {
		head = n;
		return;
	}
	node* curnode = head;
	while (curnode->next != NULL) {
		curnode = curnode->next;
	}
	curnode->next = n;	 

}

void insertfront(node* &head, int data) {

	node* newnode = new node(data);

	if (head == NULL) {
		head = newnode;
		return;
	}
	newnode->next = head;
	head = newnode;

}

//void insertanywhere(node*& head, node* prevnode, int data) {
//
//	if (prevnode == null) {
//		cout << "previous node is absent !" << endl;
//		node* newnode = new node(data);
//		newnode = head;
//		return;
//	}
//	node* newnode = new node(data);
//	node* curnode = head;
//	while (curnode != null) {
//		prevnode = curnode;
//		curnode = curnode->next;
//	}
//	if (prevnode != null && curnode->next != null) {
//		newnode->next = prevnode->next;
//		prevnode->next = newnode;
//	}
//	else {
//		cout << "inserting at tail" << endl;
//		curnode->next = newnode;
//	}
//}


bool search(node* head, int target) {
	if (head->data == target) {
		return true;
	}
	node* curnode = head;
	while (curnode != NULL) {
		if (curnode->data == target) {
			return true;
		}
		curnode = curnode->next;
	}
	return false;
}


void display(node* head) {
	node* curnode = head;
	while (curnode != NULL) {
		cout << "'" << curnode->data << "," << curnode->next << "'" << endl;
		curnode = curnode->next;
	}
}

void deletenode(node* &head, int target) {
	if (head == NULL) {
		cout << "List is alreay empty !";
		return;
	}
	if (head->data == target) {
		node* todelete = head;
		head = head->next;
		delete todelete;
		return;
	}
	node* curnode = head;
	while (curnode->next!=NULL && curnode->next->data != target) {
		curnode = curnode->next;
	}
	if (curnode->next == NULL) {
		cout << "Target not present in the linked list !" << endl;
		return;
	}
	node* abouttodel = curnode->next;
	curnode->next = curnode->next->next;
	delete abouttodel;
}

void minmax(node* head) {
	int minno = INT_MAX;
	int maxno = INT_MIN;

	node* curnode = head;
	while (curnode->next != NULL) {
		minno = min(minno, curnode->data);
		maxno = max(maxno, curnode->data);
		curnode=curnode->next;
	}
	cout << "Minimum number: " << minno << endl;
	cout << "Maximum number: " << maxno << endl;

}

node* reverseLl(node* &head) {

	node* prevnode = NULL;
	node* curnode = head;
	node* nextnode = curnode->next;

	while (curnode!=NULL) {
		nextnode =curnode->next; 
		curnode->next = prevnode;
		prevnode = curnode;
		curnode = nextnode;	
		
	}

	return prevnode;
	
}


int main() {
	
	node* head = NULL;
	inserttail(head, 12345);
	inserttail(head, 4);
	inserttail(head, 3324);
	inserttail(head, 100);
	inserttail(head, 4);

	display(head);
	cout << endl;

	node* newhead = reverseLl(head);

	display(newhead);
	cout << endl;
	display(head);
 }