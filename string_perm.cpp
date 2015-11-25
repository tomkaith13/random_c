#include <iostream>
#include <string>
using namespace std;
bool palin_flag = false;
void swap(string& s, int a, int b) {
	char temp;
	temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

bool check_palin(string s) {
	int head=0, tail = s.size()-1;
	//cout<<" intial head:"<<head<<"tail:"<<tail<<endl;
	while(head < tail) {
		if (s[head] == s[tail]) {
			head++;
			tail--;

			//cout<<"head:"<<s[head]<<"tail:"<<s[tail]<<endl;
		} else { 
			return(false);
		}
	}
	return(true);
}
bool compute_perm(string& s, int l, int r) {
	if (l == r) {
		//cout<<s<<endl;
		palin_flag |= check_palin(s);
		return (palin_flag);
		
	} 

	for(int i=l; i<r; i++) {

		if(l != i)
			swap(s,l,i);

		compute_perm(s,l+1,r);
		if (palin_flag)
			return (palin_flag);
		

		if(l != i)
			swap(s,l,i);
			

		
	}

}
int main() {
	string s="cdefghmnopqrstuvw";
	bool result;
	result = compute_perm(s, 0, s.size());



	if (palin_flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		
}