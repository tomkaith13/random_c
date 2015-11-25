#include <iostream>
#include <vector>
using namespace std;
int main() {

	vector<vector<int> > vv;

	vector<int> v1(0,10);
	vector<int> v2(0,10);
	vector<int> v3(0,10);

	//v1.emplace(v1.begin(),1);

	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);

	cout<<"vv size:"<<vv.size()<<endl;
	return(0);
}