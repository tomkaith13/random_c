#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int 
make_anagram(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	int final = 0;
	
	vector<char> v1;
	vector<char> v2;
	vector<char> v3(len1 + len2);


	vector<char>::iterator it;

	//check len of both to find the smallest

	for (int i=0;i< len1; i++)
		v1.push_back(s1[i]);

	sort(v1.begin(), v1.end());
	

	for (int i=0;i< len2; i++)
		v2.push_back(s2[i]);

	sort(v2.begin(), v2.end());

	if(v1 == v2)
		return(0);

	it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	v3.resize(it - v3.begin());

	if(v3.size() == 0)
		return(len1 + len2);

	final = (len1 - v3.size()) + (len2 - v3.size());



	return(final);


}

int main() {
	string s1;
	string s2;
	int combos=0;

	cin>>s1;
	cin>>s2;
	combos = make_anagram(s1, s2);
	cout<<combos<<endl;
	

}