#include <array>
#include <vector>
#include <iostream>
using namespace std;

class Iterator {
	vector<int> V;
public:
	Iterator(vector<int>&);
};

Iterator::Iterator(vector<int> &v) {
	V = v;
}
 
int main()
{   
 	vector<int> v(3,5);   
 	Iterator i(v);
    return(0);
 
}	