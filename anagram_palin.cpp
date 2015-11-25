#include <iostream>
#include <string>
#include <map>

using namespace std;
map<char,int> char_map;

bool is_anagram_palin(string s) {
	int one_odd=0;
	map<char,int>::iterator it;
	
	for(int i; i< s.size(); i++){
		char_map[s[i]]++;
	}

	for(it = char_map.begin(); it != char_map.end(); it++)
		cout<<it->first<<" => "<<it->second<<endl;
	
	if ((s.size()%2) == 0) {
		
		for(it = char_map.begin(); it != char_map.end(); it++) {
			if ((it->second)%2 == 0)
				continue;
			else
				return(false);
		}
		return(true);

	} else {
		// If string size is odd
		
		for(it = char_map.begin(); it != char_map.end(); it++) {
			if(one_odd > 1)
				return(false);

			if ((it->second)%2 == 0)
				continue;
			else
				one_odd++;
		}
		return (true);
	}

	
}

int main() {
	bool res;
	string s = "cdcdcdcdeeeef";
	res = is_anagram_palin(s);

	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return(0);

}