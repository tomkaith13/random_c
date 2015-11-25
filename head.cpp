#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HeapNode {
public:
	int priority;
	string name;
	HeapNode();
	HeapNode(int, string);
};

HeapNode::HeapNode() {
	priority = 0;
	name = "";
}
HeapNode::HeapNode(int p, string node_name) {
	priority = p;
	name = node_name;
}

class Heap {
	int size;	
	
	void heapify(int);
public:
	vector<HeapNode> node_list;
	Heap(int);
	Heap(int, string);
	void print_size();
	void print_heap();
	void insert_node(HeapNode);
	void sift_down(int);
	HeapNode* extract_min();
	void swap(HeapNode&, HeapNode&);
};


Heap::Heap(int sz) {
	size = sz;
}

void
Heap::print_size() {
	cout <<"Heap fixed size:"<<size<<endl;
}

void
Heap::print_heap() {
	cout<<"contents:"<<endl;
	if (node_list.size() == 0) {
		cout<<"heap empty"<<endl;
		return;
	}

	for(int i=0; i<node_list.size();i++) {
		cout<<"node prio:"<<node_list[i].priority<<endl;
		cout<<"node name:"<<node_list[i].name<<endl;
	}
}

void
Heap::insert_node(HeapNode n) {

	//check heap size
	if(node_list.size() == size) {
		cout<<"Heap is full"<<endl;
		return;
	} else {
		node_list.push_back(n);		
		heapify(node_list.size() - 1);
	}

}

void
Heap::sift_down(int p) {
	int parent = p;
	bool lmin= false;
	bool rmin = false;
	int lchild = 2*p + 1;
	int rchild = 2*p + 2;

	if ((lchild >= node_list.size()) && (rchild >= node_list.size()))
		return;

	if (lchild == (node_list.size() -1)) {
		// this means we have lchild left
		if(node_list[parent].priority > node_list[lchild].priority) {
			swap(node_list[parent], node_list[lchild]);
			return;
		}
	}

	if (node_list[lchild].priority < node_list[rchild].priority)
		lmin = true;		
	else
		rmin = true;

	if (lmin) {
		if (node_list[parent].priority > node_list[lchild].priority) {
			swap(node_list[parent], node_list[lchild]);
			sift_down(lchild);
		}
	} else if (rmin) {
		if (node_list[parent].priority > node_list[rchild].priority) {
			swap(node_list[parent], node_list[rchild]);
			sift_down(rchild);
		}
	}

}

HeapNode*
Heap::extract_min() {
	HeapNode *n = new HeapNode;
	swap(node_list[0],node_list[node_list.size() - 1]);
	*n = node_list.back();
	node_list.pop_back();
	sift_down(0);
	return(n);
}

void
Heap::heapify(int n) {
	int parent, rchild, lchild;
	if(n ==0)
		return;
	
	if (n%2 == 0) {
		parent = n/2 - 1;
		lchild = n-1;
		rchild = n;

		if (node_list[parent].priority > node_list[lchild].priority) {
			swap(node_list[parent], node_list[lchild]);
			heapify(parent);
		}

		if(node_list[parent].priority > node_list[rchild].priority) {
			swap(node_list[parent], node_list[rchild]);					
			heapify(parent);
		}
		
		
	} else {
		parent = n/2;
		lchild = n;
		rchild = n + 1;

		if(rchild >= (node_list.size()- 1)) {
			if (node_list[parent].priority > node_list[lchild].priority) {
				swap(node_list[parent], node_list[lchild]);
				heapify(parent);
				
			}
		} else {

			if (node_list[parent].priority > node_list[lchild].priority) {
				swap(node_list[parent], node_list[lchild]);
				heapify(parent);
			}

			if(node_list[parent].priority > node_list[rchild].priority) {
					swap(node_list[parent], node_list[rchild]);		
					heapify(parent);
			}
			

		}
	}
}

void 
Heap::swap(HeapNode& a, HeapNode& b) {
	HeapNode t;
	t.priority = a.priority;
	t.name.swap(a.name);
	
	a.priority = b.priority;
	a.name.swap(b.name);

	b.priority = t.priority;
	b.name.swap(t.name);
}

int main() {
	cout<<"Heap construction"<<endl;
	Heap h(7);
	HeapNode *min;

	h.print_size();
	HeapNode n6(6, "f");
	HeapNode n1(2, "a");
	HeapNode n2(3, "b");
	HeapNode n3(1, "c");
	HeapNode n7(7, "g");
	HeapNode n4(4, "d");
	HeapNode n5(5, "e");

	h.insert_node(n6);	
	h.insert_node(n1);	
	h.insert_node(n2);	
	h.insert_node(n3);
	h.insert_node(n7);
	h.insert_node(n4);
	h.insert_node(n5);
	
	
	cout<<"after insert ================"<<endl;
	h.print_heap();
	cout<<"========extracting the min node"<<endl;
	min = h.extract_min();
	cout<<"min prio:"<<min->priority<<endl;
	cout<<"min name:"<<min->name<<endl;
	cout<<"after extract_min ================"<<endl;
	h.print_heap();

	min = h.extract_min();
	cout<<"min prio:"<<min->priority<<endl;
	cout<<"min name:"<<min->name<<endl;
	cout<<"after extract_min ================"<<endl;
	h.print_heap();




	return(0);
}