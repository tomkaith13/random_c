#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

node* Head = NULL;

void
insert_node(node** Head, int d) {
	node* n = new node;
	n->data = d;
	n->next = NULL;

	if (*Head == NULL)
		*Head = n;
	else {
		n->next = *Head;
		(*Head) = n;
	}
}

void reverse_list(node** h) {
	node* t1 = NULL;
	node* t2;
	node* t3;

	t2 = *h;
	t3 = (*h)->next;

	while(t3 != NULL) {
		t2 -> next = t1;
		t1 = t2;
		t2 = t3;
		t3 = t3-> next;
	}

	t2->next = t1;
	*h = t2;
}

void print_list(node* h) {
	node* t;
	if(h == NULL) {
		cout<<" list is empty"<<endl;
		return;
	}

	for(t=h; t != NULL; t = t->next)
		cout<<"node data:"<<t->data<<endl;

}

int main() {

	cout<<"asdasdasD"<<endl;
	print_list(Head);
	insert_node(&Head,1);	
	insert_node(&Head,2);
	insert_node(&Head,3);
	insert_node(&Head,4);
	insert_node(&Head,5);			
	print_list(Head);
	cout<<"reversing================="<<endl;
	reverse_list(&Head);
	print_list(Head);
	cout<<"reversing again================="<<endl;
	reverse_list(&Head);
	print_list(Head);

}