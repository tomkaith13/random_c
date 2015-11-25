#include <iostream>
using namespace std;

class BST {
public:	
	int data;
	BST* left;
	BST* right;
	

	BST(int);
	void insert_node(int);
	void print_inorder();
	int retData();
	bool isLeaf();
	BST* goLeft();
	BST* goRight();	
};

int
BST::retData() {
	return(data);
}

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
bool 
BST::isLeaf() {
	if ((left == NULL) && (right == NULL))
		return(true);
	else
		return(false);
}

bool
childSymChecker(BST* l, BST*r) {
	bool ret = false;
	if( l->isLeaf() && r->isLeaf() ) {
		if(l->retData() == r->retData())
			return (true);
	}

	if (l->goLeft() && r->goRight())
		ret = childSymChecker(l->goLeft(), r->goRight());	
	else if((l->goLeft() == NULL) && (r->goRight() != NULL))
		ret = false;
	else if ((l->goLeft()) && (r->goRight() == NULL))
		ret = false;
	else
		ret = true; /* both are NULL, then move on*/
	

	if (!ret)
		return(false);

	if (l->goRight() && r->goLeft())
		ret = childSymChecker(l->goRight(), r->goLeft());
	else if ((l->goRight() == NULL) && (r->goLeft() != NULL))
		ret  = false;
	else if ((l->goRight() != NULL) && (r->goLeft() == NULL))
		ret = false;
	else
		ret = true; /* both are NULL, then move on*/

	if (ret)
		return (true);
	else
		return (false);	

}

bool
checkBTsym(BST* root) {

	if(root == NULL)
		return(false);

	if((root->isLeaf()))
		return(true);

	if (childSymChecker(root->goLeft(), root->goRight()))
		return (true);
	else
		return(false);
}


int main() {
	cout<<"asdads"<<endl;
	

	BST TRoot(5);
	BST a(1);
	BST b(1);
	TRoot.left = &a;
	TRoot.right = &b;
	BST c(8);
	BST d(8);
	a.left = &c;
	b.right = &d;
	BST e(9);
	BST f(9);
	c.left = &e;
	d.right = &f;
	
	cout<<"tree symmterey"<<checkBTsym(&TRoot)<<endl;
	return (0);
}