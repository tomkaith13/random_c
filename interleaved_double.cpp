#include <array>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Iterator {
	vector<T> v;
	typename vector<T>::iterator v_it;
public:
	Iterator(vector<T>&);
	bool hasNext();
	T next();
};


template <class T>
Iterator<T>::Iterator(vector<T> &vec) {
	v = vec;
	v_it = v.begin();
}

template <class T>
bool
Iterator<T>::hasNext() {

	if (v_it != v.end())
		return (true);
	else
		return (false);
}

template <class T>
T
Iterator<T>::next() {
	if (hasNext()){
		return *v_it++;
	}
	else
		return(0);
}

 
int main()
{   
 	vector<int> v{3,5,9,8,7,1,2,3,4};   
 	Iterator<int> vi(v);

 	while(vi.hasNext())
 		cout<<"vi data:"<<vi.next()<<endl;




    return(0);
 
}	