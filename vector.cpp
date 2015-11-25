#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x=0;
	vector<int> v;

	if (!v.empty())
		x = v.back();

	cout<<"x:"<<x<<endl;


	return(0);
}