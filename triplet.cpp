#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> find_trip(vector<int>, int);
int main() {

	vector<int> result;
	vector<int> input_vec;
	int inp[] = {-5,-4,-2,5,9,-5,0,10,30,44,55,666,234,22,11,222};

	for (int i=0; i < (sizeof(inp)/sizeof(inp[0])); i++)
		input_vec.push_back(inp[i]);

	result = find_trip(input_vec, 0);
	if (result.size() > 0) {
		for (int i=0; i< result.size(); i++)
			cout<<"result:"<<result[i]<<endl;
	} else {
		cout <<"No triplet found"<<endl;
	}
}

vector<int> find_trip(vector<int> input_vec, int tgt) {
	bool Flag = false;
	vector<int> res;
	map<int,int> mapI;
	map<int,int>::iterator it;
	int a,b,c;

	for(int i=0; i<input_vec.size();i++)
		mapI[input_vec[i]]++;

	for(int i=0; i<input_vec.size();i++) {
		for(int j = 0; j < input_vec.size(); j++) {
			a = input_vec[i];
			b = input_vec[j];
			c = tgt - (a+b);

			it = mapI.find(c);
			if (it != mapI.end()) {
				res.push_back(a);
				res.push_back(b);
				res.push_back(c);
				Flag = true;
				break;
			}			
		}
		if (Flag)
			break;
	}
	
	return(res);
}
