#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class node {
public:
	string data;
	node* left;
	node* right;
	node(string);
};

node::node(string d) {
	data = d;
	left = NULL;
	right = NULL;
}

void split(string s, char delim, vector<string> * v) {
	string sub_str;	
	stringstream ss(s);

	while(getline(ss, sub_str, delim)) {
		v->push_back(sub_str);
	}
}

int find(vector<string> v, string s) {
	for(int i=0;i<v.size();i++) {
		if (s.compare(v[i]) == 0)
			return (i);
	}
	return (-1);
}

void print_inorder(node* root) {
	if (!root)
		return;

	print_inorder(root->left);
	cout<<"inorder data:"<<root->data<<endl;
	print_inorder(root->right);
}

node*
buildBT(vector<string> in, vector<string> pre) {
	node* root, *left, *right;
	vector<string> l_in, r_in;
	vector<string> l_pre, r_pre;
	//string root;
	int cut;

	if (!in.size()  && !pre.size())
		return NULL;
	
	if (in.size() == 1) {
		root = new node(in[0]);
		return (root);
	}

	if (in.size() == 2) {
		root = new node(pre[0]);

		//if ((in[0].compare(pre[0]) == 0) && (in[1].compare(pre[1]) == 0)) {
		if (in == pre) {
			root = new node(pre[0]);
			right = new node(in[1]);
			root->right = right;
		} else {
			root = new node(pre[0]);
			left = new node(in[0]);
			root->left = left;
		}
		return (root);
	}

	if (in.size() == 3) {
		root =  new node(pre[0]);
		left = new node(in[0]);
		right = new node(in[2]);
		root->left = left;
		root->right = right;
		return root;		
	}

	root = new node(pre[0]);
	cut = find(in, pre[0]);
	l_in.assign(in.begin(),in.begin()+cut);
	r_in.assign(in.begin()+cut+1, in.end());
	l_pre.assign(pre.begin()+1,pre.begin()+cut+1);
	r_pre.assign(pre.begin()+cut+1,pre.end());

	/*
	cout<<"=================================="<<endl;

	cout<<"root = "<<root->data<<endl;
	cout<<"cut:"<<cut<<endl;
	for(int i =0; i < l_in.size();i++)
		cout<<"l_in:"<<l_in[i]<<endl;

	for(int i =0; i < l_pre.size();i++)
		cout<<"l_pre:"<<l_pre[i]<<endl;

	for(int i =0; i < r_in.size();i++)
		cout<<"r_in:"<<r_in[i]<<endl;

	for(int i =0; i < r_pre.size();i++)
		cout<<"r_pre:"<<r_pre[i]<<endl;
		*/

	left = buildBT(l_in, l_pre);
	right = buildBT(r_in, r_pre);
	root->left = left;
	root->right = right;
	return root;
}


int main() {
	string in_string = "4,2,8,5,9,1,6,10,3,7";
	string pre_string = "1,2,4,5,8,9,3,6,10,7";
	int cut;
	node* n;
	string c="1";

	
	vector<string> ins;
	vector<string> pre;

	split(in_string, ',', &ins);
	split(pre_string, ',', &pre);
	
	n = buildBT(ins, pre);
	//cout<<"10:"<<n->right->left->right->data<<endl;
	print_inorder(n);
	

	/*
	cut = find(ins, c);
	vector<string> t;
	
	
	
	cout<<"cut:"<<cut<<endl;
	t.assign(ins.begin(),ins.begin()+cut);

	for(int i=0;i<t.size();i++) {
		cout<<"left in:"<<t[i]<<endl;
	}

	t.assign(ins.begin()+cut+1, ins.end());

	for(int i=0;i<t.size();i++) {
		cout<<"right in:"<<t[i]<<endl;
	}

	t.assign(pre.begin()+1, pre.begin()+cut+1);
	for(int i=0;i<t.size();i++) {
		cout<<"left pre:"<<t[i]<<endl;
	}
	t.assign(pre.begin()+cut+1, pre.end());
	for(int i=0;i<t.size();i++) {
		cout<<"right pre:"<<t[i]<<endl;
	}
	*/


	
	return(0);
}