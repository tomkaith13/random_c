/* Sort a large multiple array into one single array using less memory */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;



class node {
public:
	int priority;
	int data;
	int id;
	node(int, int, int);
};

node::node(int p, int d, int vid) {
	priority = p;
	data = d;
	id = vid;
}

class node_compare {
public:
	bool operator()(node* l, node* r) {
		return (l->data > r->data);
	}
};


int main(int argc, char** argv) {

	vector<node*> v1,v2,v3,v4,v5;
	vector<node*> final_sort;
	node* t;

	v1.push_back(new node(1,6,1));
	v1.push_back(new node(1,5,1));
	v1.push_back(new node(1,16,1));
	v1.push_back(new node(1,3,1));
	v1.push_back(new node(1,4,1));
	v1.push_back(new node(1,1,1));


	v2.push_back(new node(1,16,2));
	v2.push_back(new node(1,25,2));
	v2.push_back(new node(1,26,2));
	v2.push_back(new node(1,13,2));
	v2.push_back(new node(1,24,2));
	v2.push_back(new node(1,11,2));
	v2.push_back(new node(1,12,2));

	v3.push_back(new node(1,22,3));
	v3.push_back(new node(1,33,3));
	v3.push_back(new node(1,34,3));
	v3.push_back(new node(1,31,3));
	v3.push_back(new node(1,32,3));

	v4.push_back(new node(1,6,4));
	v4.push_back(new node(1,35,4));
	v4.push_back(new node(1,26,4));
	v4.push_back(new node(1,23,4));
	v4.push_back(new node(1,45,4));
	v4.push_back(new node(1,21,4));
	v4.push_back(new node(1,2,4));
	v4.push_back(new node(1,52,5));

	v5.push_back(new node(1,26,5));
	v5.push_back(new node(1,3,5));
	v5.push_back(new node(1,26,5));
	v5.push_back(new node(1,43,5));
	v5.push_back(new node(1,55,5));
	v5.push_back(new node(1,21,5));
	v5.push_back(new node(1,52,5));
	v5.push_back(new node(1,152,5));
	v5.push_back(new node(1,252,5));

	
	sort (v1.begin(), v1.end(), node_compare());
	sort (v2.begin(), v2.end(), node_compare());
	sort (v3.begin(), v3.end(), node_compare());
	sort (v4.begin(), v4.end(), node_compare());
	sort (v5.begin(), v5.end(), node_compare());

	priority_queue<node*, vector<node*>, node_compare> min_heap;

	//cout<<"v1 last:"<<v1[v1.size()-1]->data<<endl;
	min_heap.push(v1[v1.size()-1]);
	//v1.pop_back();
	//cout<<"v2 last:"<<v2[v2.size()-1]->data<<endl;
	min_heap.push(v2[v2.size()-1]);
	//v2.pop_back();
	//cout<<"v3 last:"<<v3[v3.size()-1]->data<<endl;
	min_heap.push(v3[v3.size()-1]);
	//v3.pop_back();
	//cout<<"v4 last:"<<v4[v4.size()-1]->data<<endl;
	min_heap.push(v4[v4.size()-1]);
	//v4.pop_back();
	//cout<<"v5 last:"<<v5[v5.size()-1]->data<<endl;
	min_heap.push(v5[v5.size()-1]);
	//v5.pop_back();



	
	while(!min_heap.empty()) {

		t = min_heap.top();
		final_sort.push_back(t);
		min_heap.pop();
		if (min_heap.empty())
			break;


		if (t->id == 1) {			
			v1.pop_back();
			if (!v1.empty())
				min_heap.push(v1[v1.size()-1]);			
		}
		else if(t->id == 2) {
			v2.pop_back();
			if (!v2.empty())
				min_heap.push(v2[v2.size()-1]);
		}
		else if(t->id == 3) {
			v3.pop_back();
			if(!v3.empty())
				min_heap.push(v3[v3.size()-1]);
		}
		else if(t->id == 4) {
			v4.pop_back();
			if(!v4.empty())
				min_heap.push(v4[v4.size()-1]);
		}
		else if(t->id == 5) {
			v5.pop_back();
			if(!v5.empty())
				min_heap.push(v5[v5.size()-1]);
		}
	}
	



	

	return (0);
}