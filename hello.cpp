#include <iostream>
#include <string>

using namespace std;


void swap(string &s, int a, int b) {
	char temp;

	temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}
int main() {
	string s("Hello");
	cout<<s<<endl;

	swap(s,0,1);
	cout<<s<<endl;

	return(1);
}
