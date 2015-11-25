#include <iostream>
#include <queue>

using namespace std;

template <class T>
class node {
public:
	node* next;
	T data;
	node();
	node(T);	
};
template <class T>
node<T>::node() {
	data = -1;
	next = NULL;
}
template <class T>
node<T>::node(T d) {
	data = d;
	next = NULL;
}


class node_compare {
public:
	template <typename T>
	bool operator()(node<T> l, node<T> r) {
		if (l.data > r.data)
			return true;
		else
			return false;
	}
};



int main() {

	cout<<"Hello"<<endl;
	priority_queue<node<int>, vector< node<int> >, node_compare> node_min_pq;

	node<int> a(5);
	node<int> b(10);
	node<int> c(11);
	node<int> d(12);
	node<int> e(1);

	node<int> top;
	node_min_pq.push(a);
	node_min_pq.push(b);
	node_min_pq.push(c);
	node_min_pq.push(d);
	node_min_pq.push(e);

	top = node_min_pq.top();
	cout<<"top data:"<<top.data<<endl;
	node_min_pq.pop();
	top = node_min_pq.top();
	cout<<"next top data:"<<top.data<<endl;
	return(0);
}