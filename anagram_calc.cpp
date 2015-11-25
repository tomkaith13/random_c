#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char,int> cmap1;
map<char,int> cmap2;
map<char, int>::iterator imap1;
map<char, int>::iterator imap2;

int calculate_anagram(string s) {
	string s1, s2;
	int i, sum=0;
	int s1_len, s2_len;
	int count1=0, count2=0;
	int slen  = s.size();

	if (slen%2 != 0)
		return (-1);

	s1_len = slen/2;
	s2_len = slen - s1_len;


	s1 = string(s,0,s1_len);
	s2 = string(s,s1_len, slen-1);



	for(i=0;i<s1_len;i++)
		cmap1[s1[i]]++;

	for(i=0;i<s2_len;i++)
		cmap2[s2[i]]++;

	for(imap1 = cmap1.begin(); imap1 != cmap1.end(); imap1++) {
		count1 = imap1->second;

		imap2 = cmap2.find(imap1->first);

		if (imap2 == cmap2.end())
			count2 = 0;
		else
			count2 = imap2->second;

		sum += min(count1, count2);
	}
	cout<<"to work:"<<s1_len-sum<<endl;
	return(s1_len - sum)
	
}

int main() {
	int x;
	string s = "aaabbb";

	x = calculate_anagram(s);
	cout<<"num of changes"<<x<<endl;
}