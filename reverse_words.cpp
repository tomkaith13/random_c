#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	size_t start;
	size_t end;
	string yoda = "Free you are";

	yoda = string(yoda.rbegin(), yoda.rend());
	cout<<"yoda:"<<yoda<<endl;

	start = 0;
	while(1) {
		end = yoda.find(" ", start);

		if(end == string::npos) {
			cout<<"rev word:"<<string(yoda.rbegin() , yoda.rend()-start)<<endl;			
			break;
		}
		cout<<"start:"<<start<<"end:"<<end<<endl;
		cout<<"rev word:"<<string(yoda.rbegin()+(yoda.size()-end), yoda.rend()-start)<<endl;

		start = end+1;
		//sleep(5);
		
		

	}
	
}
