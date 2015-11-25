#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;


class pair_compare {
public:
	bool operator() (pair<int, int> l, pair<int, int> r) {
		return(l.second > r.second);
	}
};

void
distribute_bonus(vector<int> loc) {
	pair<int, int> temp_pair;
	vector<int> bonus;

	priority_queue<pair<int, int>, vector<pair<int,int> >, pair_compare> code_pq;


	for (int i=0; i< loc.size();i++) {
		bonus.push_back(0);
		temp_pair.first = i;
		temp_pair.second = loc[i];
		code_pq.push(temp_pair);
	}

	while(!code_pq.empty()) {
		temp_pair = code_pq.top();
		cout<<"top pair:"<<temp_pair.first<<","<<temp_pair.second<<endl;
		int i = temp_pair.first;

		
		
		if ((temp_pair.first == 0) || (temp_pair.first == (loc.size()-1))) {
			// only check the one neighbhor

			if (temp_pair.first == 0) {				
					bonus[0] = bonus[1]+1;
			} else{				
					bonus[loc.size()-1] = bonus[loc.size()-2] + 1;
			}
		} else {
			// two neighbors... take max of them, add 1 to it and assign
			i = temp_pair.first;
			bonus[i] = max(bonus[i-1], bonus[i+1]) + 1;
		}
		

		code_pq.pop();
	}

	for (int i = 0; i<loc.size();i++) {
		cout<<"bonus:"<<bonus[i]<<endl;
	}



}

int main() {

	vector<int> bonus_dist;
	vector<int> code_dist;
	int loc_dist[] = {100,500,200,300,400};

	code_dist.assign(loc_dist, loc_dist + (sizeof(loc_dist)/sizeof(int)));
	distribute_bonus(code_dist);


	return(0);
}