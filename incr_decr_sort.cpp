#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void
heapsort(vector<int> iv) {
	vector<vector<int> > vv;
	vector<int> index, temp1;
	int l = 0, r;
	int c=0;
	
	for(int i=1;i<iv.size()-2;i++) {
		if (((iv[i-1] < iv[i]) && (iv[i] > iv[i+1])) 
			|| ((iv[i-1] > iv[i]) && (iv[i] < iv[i+1])))
			index.push_back(i);
	}

	for(int i=0;i<index.size();i++)
		cout<<"index:"<<index[i]<<endl;
	
	l = 0;
	r = index[c];

	while(1) {
		if (iv[l] < iv[r]) {
			// just insert into temp1 and add to vector of vector
			temp1.assign(iv.begin()+l, iv.begin()+r+1);
			vv.push_back(temp1);
			temp1.erase(temp1.begin(), temp1.end());			
		} else {
			reverse(iv.begin()+l,iv.begin()+r+1);
			temp1.assign(iv.begin()+l, iv.begin()+r+1);
			vv.push_back(temp1);
			temp1.erase(temp1.begin(), temp1.end());

		}

		if (r == iv.size()-1) // final case to break from the while loop
			break;

		l = r+1;
		c++;
		
		if (c <= index.size()-1)
			r = index[c];
		else {
			r = iv.size()-1;
		}
	}

	for(int i = 0; i < vv.size();i++){
		for(int j=0; j<vv[i].size(); j++) {
			cout<<"vv:"<<vv[i][j]<<endl;
		}
		cout<<endl;
	}
	// now use external merge sort using min heap


} 
int main() {

	vector<int> input;
	int arr[] = {57,131,493,294,22,1,221,339,418,452,442,190};
	input.assign(arr, arr + (sizeof(arr) /sizeof(int)));

	
	heapsort(input);
	return (0);
}