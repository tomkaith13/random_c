#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector < map<char,int> > map_list;

void create_min_map(string s) {
	map<char,int> minerals;
	map<char,int>::iterator it;

	for (int i=0; i< s.size(); i++) {
		minerals[s[i]]++;
	}
	
	map_list.push_back(minerals);
}

int find_common_minerals() {

	map<char, int> ref_map;
	map<char, int> temp_map;
	
	int common_minerals=0;
	int final_cnt = 0;
	
	map<char, int>::iterator it;
	ref_map = map_list[0];
	map_list.erase(map_list.begin());

	
	cout<<"map list size:"<<map_list.size()<<endl;

	for(int i=0; i < map_list.size(); i++) {
		temp_map = map_list[i];
		
		for(it = temp_map.begin(); it != temp_map.end(); it++)
			cout<<it->first<<"=>"<<it->second<<endl;		
	}
	

	for(it = ref_map.begin(); it != ref_map.end(); it++) {
		for(int i=0; i<map_list.size(); i++) {
			if(map_list[i].find(it->first) != map_list[i].end())
				common_minerals++;
		}

		if(common_minerals == map_list.size())
			final_cnt++;
		common_minerals = 0;

	}
	return(final_cnt);
}

using namespace std;
int main() {

	int rocks_num;
	int no_min = 0;
	string minerals;
	cin>>rocks_num;

	while(rocks_num) {
		cin>>minerals;
		create_min_map(minerals);
		rocks_num--;
	}

	no_min = find_common_minerals();
	cout<<no_min<<endl;
	return (0);
}