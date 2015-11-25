#include <iostream>
#include <deque>
using namespace std;

class BTree {
public:
	int data;
	BTree* left;
	BTree* right;
	
	BTree(int);
};
BTree::BTree(int d) {
	data = d;
	left = NULL;
	right = NULL;
	
}



void 
BFS(BTree *root, deque<BTree*> &d) {
	int i = 0,popped = 0;
	BTree *t;
	
	d.push_back(root);
	while(d.size()) {		
		t = d.front();
		d.pop_front();		

		cout<<"BFS:"<<t->data<<endl;

		if(t->left)
			d.push_back(t->left);
		if(t->right)
			d.push_back(t->right);
	}
}

int main() {
	deque<BTree*> dq;

	BTree a(1);
	BTree b(2);
	BTree c(3);
	BTree d(4);
	BTree e(5);
	BTree f(6);
	BTree g(7);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	BFS(&a, dq);


	

	return (0);


}