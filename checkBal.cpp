#include <iostream>
using namespace std;

class BST {
	int data;
	BST* left;
	BST* right;
	
public:	
	BST(int);
	void insert_node(int);
	void print_inorder();
	BST* goLeft();
	BST* goRight();	
};

BST::BST(int n):
data(n), left(NULL), right(NULL) {	
}

BST*
BST::goLeft() {
	return(left);
}

BST*
BST::goRight() {
	return(right);
}

void
BST::insert_node(int n){

	if (n <= data) {
		if (left == NULL)
			left = new BST(n);
		else
			left->insert_node(n);		
	} else {
		if (right == NULL)
			right = new BST(n);
		else
			right->insert_node(n);
	}
	
}

void
BST::print_inorder() {
	if ((left == NULL) && (right == NULL)) {
		cout<<"data:"<<data<<endl;
		return;
	}

	if(left)
		left->print_inorder();

	cout<<"data:"<<data<<endl;

	if(right)
		right->print_inorder();
}


int
checkBal(BST* root, int h) {
	int lh=0, rh=0;
	if ((root->goLeft() == NULL) &&(root->goRight() == NULL))
		return(h);

	if(root->goLeft())
		lh = checkBal(root->goLeft(), h+1);
	if(root->goRight())
		rh = checkBal(root->goRight(), h+1);

	if((lh == -1) || (rh == -1))
		return (-1);
	if (lh == rh)
		return(lh);
	else if((lh == 0) && (rh != 0))
		return(rh);
	else if((rh == 0) && (lh != 0))
		return(lh); 
	else if ((lh == (rh-1)) ||(rh == (lh-1)))
		return ((lh<rh)?rh:lh);
	else
		return (-1);

}


int main() {
	cout<<"asdads"<<endl;
	

	BST TRoot(5);
	TRoot.insert_node(8);
	TRoot.insert_node(7);
	TRoot.insert_node(9);
	TRoot.insert_node(2);
	TRoot.insert_node(1);
	TRoot.insert_node(4);
	//TRoot.insert_node(10);

	cout<<"printing"<<endl;
	TRoot.print_inorder();
	cout<<checkBal(&TRoot,0)<<endl;
	return (0);
}