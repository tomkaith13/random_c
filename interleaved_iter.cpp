#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


template <class T>
class myIter {
	int current_vec;
	vector<typename vector<T>::iterator> it_vec;	
	vector<vector<T> > data;
	
public:
	myIter(vector<vector<T> > vector_matrix) {
		data = vector_matrix;
		vector<T> t;

		for (int i = 0; i < data.size(); i++) {			
			//vec_size.push_back(data[i].size());
			it_vec.push_back(data[i].begin());			
		}
		current_vec = 0;
	}

	T next();
	bool hasNext();

};

template <class T>
T myIter<T>::next() {
	int vsize = it_vec.size();
	T final_data;
	int flag = 0;
	
	if (hasNext()) {		
		final_data = 0;
		final_data = *(it_vec[current_vec]);
		//cout<<"currently processed vector:"<<current_vec<<endl;
		//cout<<"currently processed data:"<<*(it_vec[current_vec])<<endl;
		if (it_vec[current_vec] != data[current_vec].end())
			++(it_vec[current_vec]);

		if (current_vec == vsize-1)
			current_vec = 0;
		else
			current_vec++;

		return(final_data);
	} else {
		return(-1);
	}
}

template<class T>
bool 
myIter<T>::hasNext() {
	int flag = 1;
	T final_data;
	if (it_vec[current_vec] != data[current_vec].end())
		return (true);
	else {
		while (it_vec[current_vec] == data[current_vec].end()) {
			if (current_vec == it_vec.size()-1)
				current_vec = 0;
			else
				current_vec++;

			if (it_vec[current_vec] == data[current_vec].end())
				flag++;
			else 
				return(true);				
				
			if (flag == it_vec.size())
				break;
		}
		return (false);	
	}
}



int
main() {
	vector<vector<int> > data;	

	vector<int> v1(4,4);	
	vector<int> v2(2,5);	
	vector<int> v3(1,8);

	data.push_back(v1);
	data.push_back(v2);
	data.push_back(v3);
	
	myIter<int> my_it(data);

	while(my_it.hasNext())		
		cout<<"interleaved data:"<<my_it.next()<<endl;



	return (0);
}