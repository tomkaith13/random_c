#include <iostream>
#include <vector>

using namespace std;

void
printSpiral(vector<vector<int> > m, 
			int startR, 
			int endR, 
			int startC, 
			int endC) {

	cout<<"sr:"<<startR<<" er:"<<endR<<" sc:"<<startC<<" ec:"<<endC<<endl;

	//stopping condition
	if ((startR > endR) || (startC > endC))
		return;

	// top row printing	
	for(int i = startC; i<endC; i++)
		cout<<m[startR][i]<<" ";
	cout<<endl;

	// rightmost col printing	
	for(int i = startR+1; i < endR;i++)
		cout<<m[i][endC-1]<<" ";
	cout<<endl;

	// bottom-most row printing
	if (startR != endR-1) {
		for(int i = endC-2; i >= startC; i--)
			cout<<m[endR-1][i]<<" ";
	}
	cout<<endl;

	//leftmost col printing
	if (startC != endC-1) {
		for(int i = endR-2; i >= startR+1; i--)
			cout<<m[i][startC]<<" ";
	}
	cout<<endl;
	cout<<"====================="<<endl;
	printSpiral(m,startR+1,endR-1, startC+1, endC-1);	

}


int main() {

	vector<int> v1 { 1,2,3};
	vector<int> v2 { 11,12,13 };
	vector<int> v3 { 21,22,23 };
	vector<int> v4 { 31,32,33 };
	vector<int> v5 { 41,42,43 };
	vector<vector<int> > v {v1, v2, v3, v4, v5};

	printSpiral(v,0,5,0,3);	
}