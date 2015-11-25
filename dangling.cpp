#include <iostream>

using namespace std;

int main() {

	int *ptr;	
	ptr = new int(5);

	delete ptr;
	*ptr = 15;

	cout<<"ptr="<<*ptr<<endl;
	return(0);
}